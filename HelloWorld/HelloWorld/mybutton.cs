using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows;
using System.Diagnostics;
namespace HelloWorld
{
    public partial class mybutton : Button
    {
        Button aButton;
        public mybutton()
        {
            InitializeComponent();
            aButton = new Button();
        }
        public void mybuttonHandler(object Sender, RoutedEventArgs e)
        {
            Debug.Write("myButtonClicked");
        }
    }
}
