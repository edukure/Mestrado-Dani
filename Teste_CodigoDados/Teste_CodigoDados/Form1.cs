using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace Teste_CodigoDados
{
    public partial class Form1 : Form
    {
        char Comando;
        string Comandos;
        
        //string Colisao;
        //string Tempo;
        int teste = 0;


        public Form1()
        {
            InitializeComponent();
            timerCOM.Enabled = true;
            serialPort1.BaudRate = 9600;
            
        }

        private void atualizaListaCOMs()
        {
            int i;
            bool quantDiferente;    //flag para sinalizar que a quantidade de portas mudou

            i = 0;
            quantDiferente = false;

            //se a quantidade de portas mudou
            if (comboBox1.Items.Count == SerialPort.GetPortNames().Length)
            {
                foreach (string s in SerialPort.GetPortNames())
                {
                    if (comboBox1.Items[i++].Equals(s) == false)
                    {
                        quantDiferente = true;
                    }
                }
            }
            else
            {
                quantDiferente = true;
            }

            //Se não foi detectado diferença
            if (quantDiferente == false)
            {
                return;                     //retorna
            }

            //limpa comboBox
            comboBox1.Items.Clear();

            //adiciona todas as COM diponíveis na lista
            foreach (string s in SerialPort.GetPortNames())
            {
                comboBox1.Items.Add(s);
            }
            //seleciona a primeira posição da lista
            comboBox1.SelectedIndex = 0;
        }

        private void TimerCOM_Tick(object sender, EventArgs e)
        {
            atualizaListaCOMs();
        }

        private void BtConectar_Click(object sender, EventArgs e)
        {
                   

            if (serialPort1.IsOpen == false)
            {
                try
                {
                    serialPort1.PortName = comboBox1.Items[comboBox1.SelectedIndex].ToString();
                    serialPort1.Open();
                    serialPort1.DataReceived += serialPort1_DataReceived;

                }
                catch
                {
                    return;

                }
                if (serialPort1.IsOpen)
                {
                    btConectar.Text = "Desconectar";
                    comboBox1.Enabled = false;

                }
            }
            else
            {

                try
                {
                    serialPort1.Close();
                    comboBox1.Enabled = true;
                    btConectar.Text = "Conectar";
                }
                catch
                {
                    return;
                }

            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (serialPort1.IsOpen == true)  // se porta aberta 
                serialPort1.Close();            //fecha a porta
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            //Comando = (char)serialPort1.ReadChar();            //le o dado disponível na serial
            //teste = Convert.ToInt32(serialPort1.ReadLine());
            //lbComandos.Text = Convert.ToString(teste);
            this.Invoke(new EventHandler(trataDadoRecebido));   //chama outra thread para escrever o dado no text box

            
        }

        private void trataDadoRecebido(object sender, EventArgs e)
        {
            //Comandos = Convert.ToString(Comando);
            //lbComandos.Text = ("Numero de comandos: " + teste);

            string input = serialPort1.ReadLine();
            string[] inputs = input.Split(',');
            lbComandos.Text = $"Comandos {inputs[0]}";
            lbTempo.Text = $"Tempo {inputs[1]}";
            lbColisao.Text = $"Comandos {inputs[2]}";
        }
         
        private void BtDesconectar_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
                serialPort1.Close();
            btConectar.Enabled = true;
        }

        private void TimerLeitura_Tick(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen == true)
                serialPort1.Write("0");
        }
    }
}
