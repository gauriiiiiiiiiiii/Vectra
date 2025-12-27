#include <gtk/gtk.h>

void on_color_choosen(GtkColorButton *colorbutton, gpointer user_data)
{   

    // Get the RGBA color from the color button
    GdkRGBA color;
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(colorbutton), &color);

    // set the RGB values into the provided array (user_data)
    double *color_arr = (double *)user_data;
    if (color_arr)
    {
        color_arr[0] = (double)color.red;
        color_arr[1] = (double)color.green;
        color_arr[2] = (double)color.blue;
    }
}

GtkWidget *createColorChooser(double *color_arr)
{
    GtkWidget *color_button = gtk_color_button_new();
    g_signal_connect(color_button, "color-set", G_CALLBACK(on_color_choosen), color_arr);
    return color_button;
}
