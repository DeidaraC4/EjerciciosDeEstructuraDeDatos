using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace conecta4
{
    public partial class Form1: Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private Label[,] tablero;
        private Color marca;
        private Color simbolo;
        private int coincidencias, coincidenciasA, coincidenciasB, turno = 0;

        private void ganador(string empate = "")
        {
            elegir1.Enabled = false;
            elegir2.Enabled = false;
            elegir3.Enabled = false;
            elegir4.Enabled = false;
            elegir5.Enabled = false;
            elegir6.Enabled = false;
            elegir7.Enabled = false;
            reiniciar.Enabled = true;
            if (empate != "empate")
            {
                if (marca == Color.Red)
                {
                    nombreGanador.Text = "Felicidades jugador Rojo!";
                }
                else
                {
                    nombreGanador.Text = "Felicidades jugador Azul!";
                }
            } 
            else
            {
                nombreGanador.Text = "Empate! :O";
            }
            turno = 0;
        }

        private void revision()
        {
            for (int i = 0; i <= 5; i++)
            {
                coincidencias = 0;
                for (int j = 0; j <= 6; j++)
                {
                    if (tablero[i, j].BackColor == marca)
                    {
                        coincidencias += 1;
                    }
                    else
                    {
                        coincidencias = 0;
                    }
                    if (coincidencias == 4)
                    {
                        ganador();
                        return;
                    }
                }
            }
            for (int i = 0; i <= 6; i++)
            {
                coincidencias = 0;
                for (int j = 0; j <= 5; j++)
                {
                    if (tablero[j, i].BackColor == marca)
                    {
                        coincidencias += 1;
                    }
                    else
                    {
                        coincidencias = 0;
                    }
                }
                if (coincidencias >= 4)
                {
                    ganador();
                    return;
                }
            }
            for (int i = 0; i <= 2; i++)
            {
                coincidenciasA = coincidenciasB = 0;
                for (int j = 0; j <= 5 - i && coincidenciasA < 4 && coincidenciasB < 4; j++)
                {
                    if (tablero[i + j, j].BackColor == marca)
                    {
                        coincidenciasA += 1;
                    }
                    else
                    {
                        coincidenciasA = 0;
                    }
                    if (tablero[5 - i - j, j].BackColor == marca)
                    {
                        coincidenciasB += 1;
                    }
                    else
                    {
                        coincidenciasB = 0;
                    }
                }
                if (coincidenciasA == 4 || coincidenciasB == 4)
                {
                    ganador();
                    return;
                }
            }
            for (int i = 0; i <= 2; i++)
            {
                coincidenciasA = coincidenciasB = 0;
                for (int j = 0; j <= 5 - i && coincidenciasA < 4 && coincidenciasB < 4; j++)
                {
                    if (tablero[j, i + j + 1].BackColor == marca)
                    {
                        coincidenciasA += 1;
                    }
                    else
                    {
                        coincidenciasA = 0;
                    }
                    if (tablero[5 - j, i + j + 1].BackColor == marca)
                    {
                        coincidenciasB += 1;
                    }
                    else
                    {
                        coincidenciasB = 0;
                    }
                }
                if (coincidenciasA == 4 || coincidenciasB == 4)
                {
                    ganador();
                    return;
                }
            }
            if (turno == 42)
            {
                ganador("empate");
            }
        }

        private void colorear(int j)
        {
            for (int i = tablero.Length / 7 - 1; i >= 0; i--)
            {
                if (tablero[i, j].BackColor != Color.Blue && tablero[i, j].BackColor != Color.Red)
                {
                    tablero[i, j].BackColor = marca;
                    turno += 1;
                    revision();

                    if (marca == Color.Blue)
                    {
                        marca = Color.Red;
                    }
                    else
                    {
                        marca = Color.Blue;
                    }
                    break;
                }
            }
        }
            
        private void Form1_Load(object sender, EventArgs e)
        {
            tablero = new Label[6, 7]
            {
                { space00, space01, space02, space03, space04, space05, space06 },
                { space10, space11, space12, space13, space14, space15, space16 },
                { space20, space21, space22, space23, space24, space25, space26 },
                { space30, space31, space32, space33, space34, space35, space36 },
                { space40, space41, space42, space43, space44, space45, space46 },
                { space50, space51, space52, space53, space54, space55, space56 }
            };
            marca = Color.Blue;
            simbolo = Color.Blue;
        }

        private void elegir1_Click(object sender, EventArgs e)
        {
            colorear(0);
        }

        private void elegir2_Click(object sender, EventArgs e)
        {
            colorear(1);
        }

        private void elegir3_Click(object sender, EventArgs e)
        {
            colorear(2);
        }

        private void elegir4_Click(object sender, EventArgs e)
        {
            colorear(3);
        }

        private void elegir5_Click(object sender, EventArgs e)
        {
            colorear(4);
        }


        private void elegir6_Click(object sender, EventArgs e)
        {
            colorear(5);
        }

        private void elegir7_Click(object sender, EventArgs e)
        {
            colorear(6);
        }
        private void reiniciar_Click(object sender, EventArgs e)
        {
            foreach (Label ele in tablero)
            {
                ele.BackColor = Color.Silver;
            }

            nombreGanador.Text = "";

            elegir1.Enabled = true;
            elegir2.Enabled = true;
            elegir3.Enabled = true;
            elegir4.Enabled = true;
            elegir5.Enabled = true;
            elegir6.Enabled = true;
            elegir7.Enabled = true;
            reiniciar.Enabled = false;
        }
    }
}
