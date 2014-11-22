namespace SloanP7
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.nametb = new System.Windows.Forms.TextBox();
            this.accttb = new System.Windows.Forms.TextBox();
            this.CustomerNamelbl = new System.Windows.Forms.Label();
            this.AcctNumlbl = new System.Windows.Forms.Label();
            this.BankingCenterlbl = new System.Windows.Forms.Label();
            this.AcctcomboBox1 = new System.Windows.Forms.ComboBox();
            this.PINlbl = new System.Windows.Forms.Label();
            this.PINtb = new System.Windows.Forms.TextBox();
            this.returntb = new System.Windows.Forms.RichTextBox();
            this.Processbutton = new System.Windows.Forms.Button();
            this.Depositrb = new System.Windows.Forms.RadioButton();
            this.Withdrawrb = new System.Windows.Forms.RadioButton();
            this.Acctinforb = new System.Windows.Forms.RadioButton();
            this.Amounttb = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.ClearButton = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // nametb
            // 
            this.nametb.Location = new System.Drawing.Point(154, 92);
            this.nametb.Name = "nametb";
            this.nametb.Size = new System.Drawing.Size(185, 20);
            this.nametb.TabIndex = 0;
            this.nametb.Tag = "Name";
            this.nametb.TextChanged += new System.EventHandler(this.nametb_TextChanged);
            // 
            // accttb
            // 
            this.accttb.Location = new System.Drawing.Point(239, 131);
            this.accttb.Name = "accttb";
            this.accttb.Size = new System.Drawing.Size(100, 20);
            this.accttb.TabIndex = 1;
            this.accttb.Tag = "Acct Number";
            this.accttb.TextChanged += new System.EventHandler(this.accttb_TextChanged);
            // 
            // CustomerNamelbl
            // 
            this.CustomerNamelbl.AutoSize = true;
            this.CustomerNamelbl.Location = new System.Drawing.Point(37, 92);
            this.CustomerNamelbl.Name = "CustomerNamelbl";
            this.CustomerNamelbl.Size = new System.Drawing.Size(111, 13);
            this.CustomerNamelbl.TabIndex = 2;
            this.CustomerNamelbl.Text = "Enter your name here:";
            // 
            // AcctNumlbl
            // 
            this.AcctNumlbl.AutoSize = true;
            this.AcctNumlbl.Location = new System.Drawing.Point(37, 131);
            this.AcctNumlbl.Name = "AcctNumlbl";
            this.AcctNumlbl.Size = new System.Drawing.Size(193, 13);
            this.AcctNumlbl.TabIndex = 3;
            this.AcctNumlbl.Text = "Enter the 5 digit Account Number Here:";
            // 
            // BankingCenterlbl
            // 
            this.BankingCenterlbl.AutoSize = true;
            this.BankingCenterlbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BankingCenterlbl.Location = new System.Drawing.Point(60, 9);
            this.BankingCenterlbl.Name = "BankingCenterlbl";
            this.BankingCenterlbl.Size = new System.Drawing.Size(260, 33);
            this.BankingCenterlbl.TabIndex = 4;
            this.BankingCenterlbl.Text = "C# Banking Center";
            // 
            // AcctcomboBox1
            // 
            this.AcctcomboBox1.FormattingEnabled = true;
            this.AcctcomboBox1.Items.AddRange(new object[] {
            "Silver Account",
            "Gold Account"});
            this.AcctcomboBox1.Location = new System.Drawing.Point(40, 55);
            this.AcctcomboBox1.Name = "AcctcomboBox1";
            this.AcctcomboBox1.Size = new System.Drawing.Size(299, 21);
            this.AcctcomboBox1.TabIndex = 5;
            this.AcctcomboBox1.Tag = "";
            this.AcctcomboBox1.Text = "Select Your Account";
            this.AcctcomboBox1.SelectedIndexChanged += new System.EventHandler(this.AcctcomboBox1_SelectedIndexChanged);
            // 
            // PINlbl
            // 
            this.PINlbl.AutoSize = true;
            this.PINlbl.Location = new System.Drawing.Point(240, 159);
            this.PINlbl.Name = "PINlbl";
            this.PINlbl.Size = new System.Drawing.Size(28, 13);
            this.PINlbl.TabIndex = 6;
            this.PINlbl.Text = "PIN:";
            // 
            // PINtb
            // 
            this.PINtb.Location = new System.Drawing.Point(243, 175);
            this.PINtb.Name = "PINtb";
            this.PINtb.Size = new System.Drawing.Size(96, 20);
            this.PINtb.TabIndex = 7;
            this.PINtb.Tag = "PIN";
            this.PINtb.TextChanged += new System.EventHandler(this.PINtb_TextChanged);
            // 
            // returntb
            // 
            this.returntb.Location = new System.Drawing.Point(36, 274);
            this.returntb.Name = "returntb";
            this.returntb.ReadOnly = true;
            this.returntb.Size = new System.Drawing.Size(299, 105);
            this.returntb.TabIndex = 8;
            this.returntb.Text = "";
            this.returntb.TextChanged += new System.EventHandler(this.returntb_TextChanged);
            // 
            // Processbutton
            // 
            this.Processbutton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Processbutton.Location = new System.Drawing.Point(36, 245);
            this.Processbutton.Name = "Processbutton";
            this.Processbutton.Size = new System.Drawing.Size(303, 23);
            this.Processbutton.TabIndex = 9;
            this.Processbutton.Text = "Process";
            this.Processbutton.UseVisualStyleBackColor = true;
            this.Processbutton.Click += new System.EventHandler(this.Processbutton_Click);
            // 
            // Depositrb
            // 
            this.Depositrb.AutoSize = true;
            this.Depositrb.Location = new System.Drawing.Point(31, 17);
            this.Depositrb.Name = "Depositrb";
            this.Depositrb.Size = new System.Drawing.Size(61, 17);
            this.Depositrb.TabIndex = 10;
            this.Depositrb.TabStop = true;
            this.Depositrb.Text = "Deposit";
            this.Depositrb.UseVisualStyleBackColor = true;
            this.Depositrb.CheckedChanged += new System.EventHandler(this.Depositrb_CheckedChanged);
            // 
            // Withdrawrb
            // 
            this.Withdrawrb.AutoSize = true;
            this.Withdrawrb.Location = new System.Drawing.Point(31, 40);
            this.Withdrawrb.Name = "Withdrawrb";
            this.Withdrawrb.Size = new System.Drawing.Size(70, 17);
            this.Withdrawrb.TabIndex = 11;
            this.Withdrawrb.TabStop = true;
            this.Withdrawrb.Text = "Withdraw";
            this.Withdrawrb.UseVisualStyleBackColor = true;
            this.Withdrawrb.CheckedChanged += new System.EventHandler(this.Withdrawrb_CheckedChanged);
            // 
            // Acctinforb
            // 
            this.Acctinforb.AutoSize = true;
            this.Acctinforb.Location = new System.Drawing.Point(31, 63);
            this.Acctinforb.Name = "Acctinforb";
            this.Acctinforb.Size = new System.Drawing.Size(106, 17);
            this.Acctinforb.TabIndex = 12;
            this.Acctinforb.TabStop = true;
            this.Acctinforb.Text = "Get Account Info";
            this.Acctinforb.UseVisualStyleBackColor = true;
            this.Acctinforb.CheckedChanged += new System.EventHandler(this.Acctinforb_CheckedChanged);
            // 
            // Amounttb
            // 
            this.Amounttb.Location = new System.Drawing.Point(243, 219);
            this.Amounttb.Name = "Amounttb";
            this.Amounttb.Size = new System.Drawing.Size(96, 20);
            this.Amounttb.TabIndex = 13;
            this.Amounttb.Tag = "Amount";
            this.Amounttb.TextChanged += new System.EventHandler(this.Amounttb_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(240, 203);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 14;
            this.label1.Text = "Amount: ";
            // 
            // ClearButton
            // 
            this.ClearButton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.ClearButton.Location = new System.Drawing.Point(32, 385);
            this.ClearButton.Name = "ClearButton";
            this.ClearButton.Size = new System.Drawing.Size(307, 23);
            this.ClearButton.TabIndex = 15;
            this.ClearButton.Text = "Clear";
            this.ClearButton.UseVisualStyleBackColor = true;
            this.ClearButton.Click += new System.EventHandler(this.ClearButton_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Acctinforb);
            this.groupBox1.Controls.Add(this.Depositrb);
            this.groupBox1.Controls.Add(this.Withdrawrb);
            this.groupBox1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.groupBox1.Location = new System.Drawing.Point(40, 152);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(157, 87);
            this.groupBox1.TabIndex = 16;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Options";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Green;
            this.ClientSize = new System.Drawing.Size(391, 420);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.ClearButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Amounttb);
            this.Controls.Add(this.Processbutton);
            this.Controls.Add(this.returntb);
            this.Controls.Add(this.PINtb);
            this.Controls.Add(this.PINlbl);
            this.Controls.Add(this.AcctcomboBox1);
            this.Controls.Add(this.BankingCenterlbl);
            this.Controls.Add(this.AcctNumlbl);
            this.Controls.Add(this.CustomerNamelbl);
            this.Controls.Add(this.accttb);
            this.Controls.Add(this.nametb);
            this.ForeColor = System.Drawing.SystemColors.Info;
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox nametb;
        private System.Windows.Forms.TextBox accttb;
        private System.Windows.Forms.Label CustomerNamelbl;
        private System.Windows.Forms.Label AcctNumlbl;
        private System.Windows.Forms.Label BankingCenterlbl;
        private System.Windows.Forms.ComboBox AcctcomboBox1;
        private System.Windows.Forms.Label PINlbl;
        private System.Windows.Forms.TextBox PINtb;
        private System.Windows.Forms.RichTextBox returntb;
        private System.Windows.Forms.Button Processbutton;
        private System.Windows.Forms.RadioButton Depositrb;
        private System.Windows.Forms.RadioButton Withdrawrb;
        private System.Windows.Forms.RadioButton Acctinforb;
        private System.Windows.Forms.TextBox Amounttb;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button ClearButton;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

