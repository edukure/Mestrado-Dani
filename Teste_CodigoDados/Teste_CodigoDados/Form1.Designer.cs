namespace Teste_CodigoDados
{
    partial class Form1
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btConectar = new System.Windows.Forms.Button();
            this.timerCOM = new System.Windows.Forms.Timer(this.components);
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.timerLeitura = new System.Windows.Forms.Timer(this.components);
            this.lbComandos = new System.Windows.Forms.Label();
            this.lbTempo = new System.Windows.Forms.Label();
            this.lbColisao = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btConectar
            // 
            this.btConectar.Location = new System.Drawing.Point(35, 29);
            this.btConectar.Name = "btConectar";
            this.btConectar.Size = new System.Drawing.Size(141, 31);
            this.btConectar.TabIndex = 0;
            this.btConectar.Text = "Conectar";
            this.btConectar.UseVisualStyleBackColor = true;
            this.btConectar.Click += new System.EventHandler(this.BtConectar_Click);
            // 
            // timerCOM
            // 
            this.timerCOM.Tick += new System.EventHandler(this.TimerCOM_Tick);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(196, 33);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(164, 24);
            this.comboBox1.TabIndex = 2;
            // 
            // timerLeitura
            // 
            this.timerLeitura.Interval = 500;
            this.timerLeitura.Tick += new System.EventHandler(this.TimerLeitura_Tick);
            // 
            // lbComandos
            // 
            this.lbComandos.AutoSize = true;
            this.lbComandos.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbComandos.Location = new System.Drawing.Point(218, 140);
            this.lbComandos.Name = "lbComandos";
            this.lbComandos.Size = new System.Drawing.Size(194, 32);
            this.lbComandos.TabIndex = 3;
            this.lbComandos.Text = "Comandos: 0";
            // 
            // lbTempo
            // 
            this.lbTempo.AutoSize = true;
            this.lbTempo.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbTempo.Location = new System.Drawing.Point(248, 197);
            this.lbTempo.Name = "lbTempo";
            this.lbTempo.Size = new System.Drawing.Size(142, 32);
            this.lbTempo.TabIndex = 5;
            this.lbTempo.Text = "Tempo: 0";
            // 
            // lbColisao
            // 
            this.lbColisao.AutoSize = true;
            this.lbColisao.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbColisao.Location = new System.Drawing.Point(238, 253);
            this.lbColisao.Name = "lbColisao";
            this.lbColisao.Size = new System.Drawing.Size(152, 32);
            this.lbColisao.TabIndex = 7;
            this.lbColisao.Text = "Colisão: 0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lbColisao);
            this.Controls.Add(this.lbTempo);
            this.Controls.Add(this.lbComandos);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.btConectar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btConectar;
        private System.Windows.Forms.Timer timerCOM;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer timerLeitura;
        private System.Windows.Forms.Label lbComandos;
        private System.Windows.Forms.Label lbTempo;
        private System.Windows.Forms.Label lbColisao;
    }
}

