using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Relogio
{
    class Relogio
    {
        int hora, min, seg;
        Timer temporizador;

        public Relogio(int hora, int min, int seg)
        {
            this.hora = hora; this.min = min; this.seg = seg;
            temporizador = new Timer();
            temporizador.Interval = 1000;
            temporizador.Enabled = true;
            temporizador.Tick += new EventHandler(Tick_tempo);
        }
        public string AtualizarHora()
        {
            return "" + hora + ":" + min + ":" + seg;
        }
        public void Tick_tempo(object sender, EventArgs e)
        {
            
            seg += 1;
            if (seg == 61)
            {
                seg = 0;
                min++;
            }
            if (min == 61)
            {
                hora++;
                min = 0;
            }
            if (hora == 25)
            { hora = 0; }
        }
    }
 }
