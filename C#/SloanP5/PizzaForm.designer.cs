namespace SloanP5
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lblTitle = new System.Windows.Forms.Label();
            this.rblarge = new System.Windows.Forms.RadioButton();
            this.rbmedium = new System.Windows.Forms.RadioButton();
            this.rbsmall = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lbltoppings = new System.Windows.Forms.Label();
            this.cbPepperoni = new System.Windows.Forms.CheckBox();
            this.cbMushroom = new System.Windows.Forms.CheckBox();
            this.cbOlives = new System.Windows.Forms.CheckBox();
            this.cbCheese = new System.Windows.Forms.CheckBox();
            this.cbPineapple = new System.Windows.Forms.CheckBox();
            this.cbGreenChili = new System.Windows.Forms.CheckBox();
            this.cbbCrust = new System.Windows.Forms.ComboBox();
            this.btnPlaceOrder = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.BackColor = System.Drawing.Color.Goldenrod;
            this.lblTitle.Font = new System.Drawing.Font("Perpetua", 18F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(76, 28);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(410, 140);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Welcome to Paisanos Pizza.\r\nSelect Your Size, Choose Toppings and Crust Type.\r\n\r\n" +
    "\r\n\r\n";
            // 
            // rblarge
            // 
            this.rblarge.AutoSize = true;
            this.rblarge.BackColor = System.Drawing.Color.Transparent;
            this.rblarge.Location = new System.Drawing.Point(18, 65);
            this.rblarge.Name = "rblarge";
            this.rblarge.Size = new System.Drawing.Size(84, 17);
            this.rblarge.TabIndex = 1;
            this.rblarge.TabStop = true;
            this.rblarge.Text = "14\" - $14.99";
            this.rblarge.UseVisualStyleBackColor = false;
            // 
            // rbmedium
            // 
            this.rbmedium.AutoSize = true;
            this.rbmedium.Location = new System.Drawing.Point(18, 42);
            this.rbmedium.Name = "rbmedium";
            this.rbmedium.Size = new System.Drawing.Size(84, 17);
            this.rbmedium.TabIndex = 2;
            this.rbmedium.TabStop = true;
            this.rbmedium.Text = "12\" - $12.99";
            this.rbmedium.UseVisualStyleBackColor = true;
            // 
            // rbsmall
            // 
            this.rbsmall.AutoSize = true;
            this.rbsmall.Checked = true;
            this.rbsmall.Location = new System.Drawing.Point(18, 20);
            this.rbsmall.Name = "rbsmall";
            this.rbsmall.Size = new System.Drawing.Size(87, 17);
            this.rbsmall.TabIndex = 3;
            this.rbsmall.TabStop = true;
            this.rbsmall.Text = "10\" -  $10.99";
            this.rbsmall.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbsmall);
            this.groupBox1.Controls.Add(this.rblarge);
            this.groupBox1.Controls.Add(this.rbmedium);
            this.groupBox1.Location = new System.Drawing.Point(81, 109);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 89);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Size";
            // 
            // lbltoppings
            // 
            this.lbltoppings.AutoSize = true;
            this.lbltoppings.Location = new System.Drawing.Point(429, 109);
            this.lbltoppings.Name = "lbltoppings";
            this.lbltoppings.Size = new System.Drawing.Size(100, 26);
            this.lbltoppings.TabIndex = 5;
            this.lbltoppings.Text = "Additional Toppings\r\n$1.00 Each\r\n";
            // 
            // cbPepperoni
            // 
            this.cbPepperoni.AutoSize = true;
            this.cbPepperoni.Location = new System.Drawing.Point(432, 161);
            this.cbPepperoni.Name = "cbPepperoni";
            this.cbPepperoni.Size = new System.Drawing.Size(74, 17);
            this.cbPepperoni.TabIndex = 6;
            this.cbPepperoni.Text = "Pepperoni";
            this.cbPepperoni.UseVisualStyleBackColor = true;
            // 
            // cbMushroom
            // 
            this.cbMushroom.AutoSize = true;
            this.cbMushroom.Location = new System.Drawing.Point(432, 184);
            this.cbMushroom.Name = "cbMushroom";
            this.cbMushroom.Size = new System.Drawing.Size(80, 17);
            this.cbMushroom.TabIndex = 7;
            this.cbMushroom.Text = "Mushrooms";
            this.cbMushroom.UseVisualStyleBackColor = true;
            // 
            // cbOlives
            // 
            this.cbOlives.AutoSize = true;
            this.cbOlives.Location = new System.Drawing.Point(432, 207);
            this.cbOlives.Name = "cbOlives";
            this.cbOlives.Size = new System.Drawing.Size(85, 17);
            this.cbOlives.TabIndex = 8;
            this.cbOlives.Text = "Black Olives";
            this.cbOlives.UseVisualStyleBackColor = true;
            // 
            // cbCheese
            // 
            this.cbCheese.AutoSize = true;
            this.cbCheese.Location = new System.Drawing.Point(432, 138);
            this.cbCheese.Name = "cbCheese";
            this.cbCheese.Size = new System.Drawing.Size(89, 17);
            this.cbCheese.TabIndex = 9;
            this.cbCheese.Text = "Extra Cheese";
            this.cbCheese.UseVisualStyleBackColor = true;
            // 
            // cbPineapple
            // 
            this.cbPineapple.AutoSize = true;
            this.cbPineapple.Location = new System.Drawing.Point(432, 230);
            this.cbPineapple.Name = "cbPineapple";
            this.cbPineapple.Size = new System.Drawing.Size(73, 17);
            this.cbPineapple.TabIndex = 10;
            this.cbPineapple.Text = "Pineapple";
            this.cbPineapple.UseVisualStyleBackColor = true;
            // 
            // cbGreenChili
            // 
            this.cbGreenChili.AutoSize = true;
            this.cbGreenChili.Location = new System.Drawing.Point(432, 253);
            this.cbGreenChili.Name = "cbGreenChili";
            this.cbGreenChili.Size = new System.Drawing.Size(77, 17);
            this.cbGreenChili.TabIndex = 11;
            this.cbGreenChili.Text = "Green Chili";
            this.cbGreenChili.UseVisualStyleBackColor = true;
            // 
            // cbbCrust
            // 
            this.cbbCrust.FormattingEnabled = true;
            this.cbbCrust.Items.AddRange(new object[] {
            "Thin - No extra charge",
            "Thick - $1.00 extra",
            "Hand Tossed - $2.00 extra"});
            this.cbbCrust.Location = new System.Drawing.Point(81, 249);
            this.cbbCrust.Name = "cbbCrust";
            this.cbbCrust.Size = new System.Drawing.Size(212, 21);
            this.cbbCrust.TabIndex = 12;
            this.cbbCrust.Text = "Select Crust Type";
            // 
            // btnPlaceOrder
            // 
            this.btnPlaceOrder.Location = new System.Drawing.Point(293, 534);
            this.btnPlaceOrder.Name = "btnPlaceOrder";
            this.btnPlaceOrder.Size = new System.Drawing.Size(75, 23);
            this.btnPlaceOrder.TabIndex = 13;
            this.btnPlaceOrder.Text = "Place Order";
            this.btnPlaceOrder.UseVisualStyleBackColor = true;
            this.btnPlaceOrder.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(81, 534);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 14;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(81, 302);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox1.Size = new System.Drawing.Size(287, 202);
            this.textBox1.TabIndex = 15;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(554, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 78);
            this.label1.TabIndex = 16;
            this.label1.Text = "Ryan Sloan\r\nCIS 1280\r\nProgram 3\r\nSloanP3/Form1.cs\r\nrsloan2@cnm.edu\r\n\r\n";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(432, 302);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(157, 111);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 17;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Goldenrod;
            this.ClientSize = new System.Drawing.Size(652, 617);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnPlaceOrder);
            this.Controls.Add(this.cbbCrust);
            this.Controls.Add(this.cbGreenChili);
            this.Controls.Add(this.cbPineapple);
            this.Controls.Add(this.cbCheese);
            this.Controls.Add(this.cbOlives);
            this.Controls.Add(this.cbMushroom);
            this.Controls.Add(this.cbPepperoni);
            this.Controls.Add(this.lbltoppings);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.lblTitle);
            this.Name = "Form1";
            this.Text = "Sloan P3 Pizza Class";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.RadioButton rblarge;
        private System.Windows.Forms.RadioButton rbmedium;
        private System.Windows.Forms.RadioButton rbsmall;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lbltoppings;
        private System.Windows.Forms.CheckBox cbPepperoni;
        private System.Windows.Forms.CheckBox cbMushroom;
        private System.Windows.Forms.CheckBox cbOlives;
        private System.Windows.Forms.CheckBox cbCheese;
        private System.Windows.Forms.CheckBox cbPineapple;
        private System.Windows.Forms.CheckBox cbGreenChili;
        private System.Windows.Forms.ComboBox cbbCrust;
        private System.Windows.Forms.Button btnPlaceOrder;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

