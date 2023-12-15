#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

// Função para formatar o CNPJ
void formatCnpj(const char *cnpj, char *formattedCnpj) {
    int j = 0;

    // Adiciona a formatação: 20.140.394/0004-33
    snprintf(formattedCnpj, 20, "%c%c.%c%c%c.%c%c%c/%c%c%c%c-%c%c",
             cnpj[0], cnpj[1], cnpj[2], cnpj[3], cnpj[4],
             cnpj[5], cnpj[6], cnpj[7], cnpj[8],
             cnpj[9], cnpj[10], cnpj[11], cnpj[12],
             cnpj[13], cnpj[14]);
}

// Callback para o botão "Formatar e Copiar"
void button_clicked(GtkWidget *widget, gpointer data) {
    // Obtém o texto digitado
    GtkEntry *entry = GTK_ENTRY(data);
    const char *cnpj = gtk_entry_get_text(entry);

    // Formata o CNPJ
    char formattedCnpj[20]; // Ajuste o tamanho conforme necessário
    formatCnpj(cnpj, formattedCnpj);

    // Copia para a área de transferência
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, formattedCnpj, -1);
    gtk_clipboard_store(clipboard);

    // Exibe uma mensagem informando que foi copiado
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
                                               "CNPJ formatado e copiado para o clipboard:\n%s", formattedCnpj);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Cria a janela
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Formatador de CNPJ");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Cria uma caixa vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Cria a entrada de texto
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Digite o CNPJ");
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

    // Cria o botão "Formatar e Copiar"
    GtkWidget *button = gtk_button_new_with_label("Formatar e Copiar");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), entry);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    // Exibe tudo
    gtk_widget_show_all(window);

    // Inicia o loop principal
    gtk_main();

    return 0;
}
