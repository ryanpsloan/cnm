using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections.Specialized;

public partial class Flight : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void InsertButton_Click(object sender, EventArgs e)
    {
        ListDictionary parameters = new ListDictionary();
        parameters.Add("Flight_Number", FNTextBox.Text);
        parameters.Add("Date", DTextBox.Text);
        parameters.Add("Carrier_Code", CCTextBox.Text);
        parameters.Add("Tail_Number", TNTextBox.Text);
        parameters.Add("Destination_Airport", DATextBox.Text);
        parameters.Add("Scheduled_Departure_Time", SDTTextBox.Text);
        parameters.Add("Actual_Departure_Time", ADTTextBox.Text);
        parameters.Add("Scheduled_Elapsed_Time", SETTextBox.Text);
        parameters.Add("Actual_Elapsed_Time", AETTextBox.Text);

        LinqDataSource1.Insert(parameters);

        FNTextBox.Text = string.Empty;
        DTextBox.Text = string.Empty;
        CCTextBox.Text = string.Empty;
        TNTextBox.Text = string.Empty;
        DATextBox.Text = string.Empty;
        SDTTextBox.Text = string.Empty;
        ADTTextBox.Text = string.Empty;
        SETTextBox.Text = string.Empty;
        AETTextBox.Text = string.Empty;

        GridView1.DataBind();
    }
    protected void ClearButton_Click(object sender, EventArgs e)
    {
        FNTextBox.Text = string.Empty;
        DTextBox.Text = string.Empty;
        CCTextBox.Text = string.Empty;
        TNTextBox.Text = string.Empty;
        DATextBox.Text = string.Empty;
        SDTTextBox.Text = string.Empty;
        ADTTextBox.Text = string.Empty;
        SETTextBox.Text = string.Empty;
        AETTextBox.Text = string.Empty;

    }
    protected void FindButton_Click(object sender, EventArgs e)
    {
        DataClassesDataContext dataContext = new DataClassesDataContext();

        var query = from m in dataContext.Flight_Stats
                    where m.Flight_Number == Convert.ToInt32(FTextBox.Text)
                    select m;

        GridView1.DataSourceID = "";
        GridView1.DataSource = query;

        GridView1.DataBind();
        FTextBox.Text = string.Empty;
    }
    protected void ShowAllButton_Click(object sender, EventArgs e)
    {
        GridView1.DataSource = LinqDataSource1;
        GridView1.DataBind();
    }
}