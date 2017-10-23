using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;

namespace HelloWorld
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        int i = 20;
        public MainWindow()
        {
            InitializeComponent();
            mybutton customButton = new mybutton();
            Debug.Write("hello");
            Button myButton = new Button();
            myButton.Content = "MyButton";
            myButton.Width = 150;
            myButton.HorizontalAlignment = HorizontalAlignment.Left;
            myButton.VerticalAlignment = VerticalAlignment.Center;
            myButton.Margin = new Thickness(50);
            stackpanel.Children.Add(myButton);
        }

        private void mybutton_Click(object sender, RoutedEventArgs e)
        {
            i += 20;
            Debug.Write(i);
        }
        private void stackpanele_mouseover(object sender, RoutedEventArgs e)
        {
            Debug.Write("mouse moved\n");
        }
        private void close(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
