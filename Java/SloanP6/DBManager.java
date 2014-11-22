/* Laurence Mirabal
 * MirabalP8 Database
 * lmirabal3@cnm.edu
 * DBManager.java
 * 12/1/2011
*/
package mirabalp8;

import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 *
 * @author Laurence PC
 */
public class DBManager {

    //predefined strings for the database connection..
    private final String accessDBURLPrefix =
            "jdbc:odbc:Driver={Microsoft Access Driver (*.mdb)};DBQ=";
    private final String accessDBURLSuffix = ";DriverID=22;READONLY=false;}";
    //filename if the database does not open on startup
    private String filename;
    //formatted string for connection
    private Connection conn;
    
    public DBManager()
    {
        try
        {   //begin to create connection with dbname
            conn = getAccessDBConnection("Cameras.mdb");
            conn.setAutoCommit(true);
            DatabaseMetaData md = conn.getMetaData();
        } 
        catch (SQLException ex) 
        {//exception handling and message if error occurs
          Logger.getLogger(DBManager.class.getName()).log(Level.SEVERE,null,ex);
            //chooser opens if no file is found at launch
            JFileChooser chooser = new JFileChooser();
            chooser.showOpenDialog(chooser);
            //create filename from filechooser
            if(chooser.getSelectedFile() != null)
            {
            filename = chooser.getSelectedFile().toString();
            }
            else 
            {
                System.exit(0);
            }
     
            //try again..
            try
            {
                conn = getAccessDBConnection(filename);
                conn.setAutoCommit(true);
                DatabaseMetaData md = conn.getMetaData();
            } 
            catch (SQLException ex1)
            {
                Logger.getLogger(
                        DBManager.class.getName()).log(Level.SEVERE, null, ex1);
                JOptionPane.showMessageDialog(null,
                "The database could not be opened" +
                "\r\nTry launching the program again and selecting a .mdb file"
                , "Fatal Error",
                JOptionPane.ERROR_MESSAGE);
                //if the program fails again it will close and ask the user to
                //relaunch the application, otherwise the program will hang
                System.exit(0);
            }
        }
    }
        
    private Connection getAccessDBConnection(String filename) throws SQLException
    {
        try
        {//this is the bridge driver to load the database
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
        }
        catch(ClassNotFoundException e)
        {
            JOptionPane.showMessageDialog(null, e.getMessage(),
                    "Driver Error", JOptionPane.ERROR_MESSAGE);
            //if there is no connection the program will exit
            System.exit(0);
        }

        String databaseURL = accessDBURLPrefix + filename + accessDBURLSuffix;
        //connect and run db string
        return DriverManager.getConnection(databaseURL);
    }

    public String[] getList() throws SQLException
    {
        //after connection to the db prepare the .mdb fie
        String strSQL = "SELECT Company FROM Cameras;";
        PreparedStatement ps = conn.prepareStatement(
         strSQL, ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
        //load the list from the db file
        ResultSet rs = ps.executeQuery();

        rs.last();
        int rowCount = rs.getRow();
        String[] items = new String[rowCount];

        try{
            rs.beforeFirst();

            int i = 0;
            while(rs.next())
            {//display items in the beginning of my db file but not the UID
                items[i] = rs.getString("Company");
                i++;
            }
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, "Error reading file!\r\n"
                        + e.getMessage());
        }
        return items;
    }

    public int[] getIDs() throws SQLException
    {//retrieve the UID's from my .mdb file
        int[] ID;
        String strSQL = "SELECT UID FROM Cameras;";
        PreparedStatement ps = conn.prepareStatement(strSQL, ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);

        ResultSet rs = ps.executeQuery();

        rs.last();
        int rowCount = rs.getRow();
        ID = new int[rowCount];

        try
        {
            rs.beforeFirst();

            int i = 0;
            while(rs.next())
            {
                ID[i] = rs.getInt("UID");
                i++;
            }
        }
        catch(Exception e)
        {//if no UID found in file
       JOptionPane.showMessageDialog(null,"No Records Found!" + e.getMessage());
        }

        int count = getRecordCount(rs);

        return ID;
    }

    public int getRecordCount(ResultSet rs) throws SQLException
    {//count number of records in db file
        int recordCount = 0;

        rs.beforeFirst();
        while(rs.next())
        {
            recordCount++;
        }
     return recordCount;
    }

    public void insert(String x, String y, String z) throws SQLException
    {//insert records from new,delete and edit panels
        insertRecord(x, y, z);
    }

    private void insertRecord(String tableName, String columnList, String valueList) throws SQLException
    {//sql for inserting a record into the db
        Statement st = conn.createStatement();
        String strSQL = "INSERT INTO " + tableName + " " + columnList + " VALUES (" + valueList + ");";

        try
        {   //record add with no problem
            st.execute(strSQL);
            JOptionPane.showMessageDialog(null,"Record Added!",
                    "New Record Added", JOptionPane.INFORMATION_MESSAGE);
        }
        catch(SQLException e)
        {//record failed to be added
            JOptionPane.showMessageDialog(null, "Record Not Added!\n " +
                    e.getMessage(),"Insert Error", JOptionPane.ERROR_MESSAGE);
        }
        //close the connection
        st.close();
    }

    public String[] getRecord(int UID) throws SQLException
    {
        //record array
        String[] rec;
        //retrieve records for array to display in
        //jList in EditPanel and DeletePanel
        String strSQL = "SELECT * FROM Cameras WHERE UID = " + UID + ";";
        PreparedStatement ps = 
        conn.prepareStatement(strSQL, ResultSet.TYPE_SCROLL_INSENSITIVE,
             ResultSet.CONCUR_READ_ONLY);
        //query formatted string
        ResultSet rs = ps.executeQuery();
        ResultSetMetaData rsMeta = rs.getMetaData();
        int columns = rsMeta.getColumnCount();
        rec = new String[columns];
        try
        {
            rs.beforeFirst();
            int i = 0;
            while(rs.next())
            {
                for(i = 0; i < columns; i++)
                {
                    rec[i] = rs.getString(i+1);
                }
            }
        }
        catch(SQLException e)
        {//catch exception
        Logger.getLogger(DeletePanel.class.getName()).log(Level.SEVERE,null,e);
        }
        return rec;
    }

    public void delete(int UID) throws SQLException
    {//delete record fromm DeletePanel
        deleteRecord(UID);
    }

    private void deleteRecord(int ID) throws SQLException
    {   //sql to delete record from DeletePanel
        String strSQL = "DELETE * FROM Cameras WHERE UID = " + ID + ";";
        PreparedStatement ps =
                conn.prepareStatement(strSQL, ResultSet.TYPE_SCROLL_INSENSITIVE,
                ResultSet.CONCUR_UPDATABLE);
        try
        {
            ps.execute();
        }
        catch(SQLException ex)
        {//if not deleted correctly
            JOptionPane.showMessageDialog(null,
                        "Delete failed!\n" + ex.getMessage());
        }
    }

    public void edit(String tbl, String sets, String where) throws SQLException
    {
        updateRecord(tbl, sets, where);
    }

    private void updateRecord(
            String table, String sets, String where) throws SQLException
    {
        //same as the delete record but updates info in the db
        String strSQL = "UPDATE " + table + " SET " + sets + " WHERE " + where;
        PreparedStatement ps = conn.prepareStatement(strSQL,
                ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        try
        {
            ps.execute();
            JOptionPane.showMessageDialog(null, "SUCCESS!");
        }
        catch(SQLException ex)
        {
            JOptionPane.showMessageDialog(null, "Update failed:\n" +
                    ex.getMessage());
        }
    }
}