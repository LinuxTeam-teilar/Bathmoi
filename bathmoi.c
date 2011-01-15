#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_LESSONS 67
#define LESSONS_PER_DIR 50
#define LESSONS_TO_END 41

struct lesson {
    GtkWidget *checkbtn;
    GtkWidget *title;
    GtkWidget *entry;
    GtkWidget *code;
    int DM;
};

GtkWidget *addTitle(gchar *);
void addLesson(gchar *, gint, char *, char *, GtkWidget *);
void checkbtnToggle(GtkWidget *, gint);
gint epilogiKate(void);
GtkWidget *addButtons();
void calculate();
void aboutClicked();
int checkTable(struct lesson []);
char **icon();

GtkWidget *main_window;

int i;
struct lesson lessons[NUM_OF_LESSONS];

int main(int argc, char *argv[])
{
    GtkWidget *exp, *vbox1, *vbox, *hbox;
    gint kateuth = 0;
    i = 0;

    gtk_init (&argc, &argv);

    kateuth = epilogiKate();

    main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_icon (GTK_WINDOW(main_window), gdk_pixbuf_new_from_xpm_data((const char **) pixmap));
    gtk_window_set_icon (GTK_WINDOW(main_window), gdk_pixbuf_new_from_xpm_data((const char **) icon()));
    gtk_window_set_title (GTK_WINDOW (main_window), "Βαθμός πτυχίου!");
    gtk_window_set_default_size (GTK_WINDOW (main_window), (gint) 700, (gint) 300);
    gtk_window_set_position (GTK_WINDOW (main_window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW (main_window), FALSE);
    g_signal_connect (G_OBJECT (main_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (main_window), 10);
    vbox = gtk_vbox_new (FALSE, 5);

    hbox = gtk_hbox_new (FALSE, 5);
    gtk_box_pack_start (GTK_BOX(hbox), gtk_label_new("Κωδικός"), FALSE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX(hbox), gtk_label_new("Όνομα μαθήματος"), FALSE, FALSE, 5);
    gtk_box_pack_end (GTK_BOX(hbox), gtk_label_new("Δ.Μ."), FALSE, FALSE, 5);
    gtk_box_pack_end (GTK_BOX(hbox), gtk_label_new("Βαθμός"), FALSE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX(vbox), hbox, FALSE, FALSE, 5);

    /* PROTO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("1o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    addLesson("Μαθηματική ανάλυση I", 0, "5", "[120]", vbox1);
    addLesson("Φυσική", 0, "5", "[121]", vbox1);
    addLesson("Προγραμματισμός I", 0, "5", "[122]", vbox1);
    addLesson("Αρχές Τηλεπικοινωνιών", 0, "5", "[123]", vbox1);
    addLesson("Ηλεκτρονικά", 0, "5", "[124]", vbox1);
    addLesson("Διακριτά συστήματα", 0, "5", "[125]", vbox1);

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);

    /* DEYTERO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("2o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    addLesson("Μαθηματική ανάλυση II", 0, "5", "[220]", vbox1);
    addLesson("Φυσικές Αρχές Τεχνολογίας Επικοινωνιών", 0, "6", "[221]", vbox1);
    addLesson("Αρχιτεκτονική Η/Υ I", 0, "5", "[223]", vbox1);
    addLesson("Ηλεκτρονικές Τηλεπικοινωνίες", 0, "5", "[224]", vbox1);
    addLesson("Αριθμητική ανάλυση", 0, "5", "[225]", vbox1);
    addLesson("Προγραμματισμός II", 0, "5", "[226]", vbox1);

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);

    /* TRITO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("3o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    addLesson("Βάσεις δεδομένων I", 0, "5", "[320]", vbox1);
    addLesson("Δομές δεδομένων και αλγόριθμοι", 0, "5", "[321]", vbox1);
    addLesson("Θεωρία πιθανοτήτων και στατιστική", 0, "5", "[322]", vbox1);
    addLesson("Δίκτυα I", 0, "5", "[323]", vbox1);
    addLesson("Λειτουργικά συστήματα I", 0, "5", "[324]", vbox1);
    addLesson("Εφαρμογές γραμμική άλγεβρας", 0, "5", "[325]", vbox1);

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);

    /* TETARTO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("4o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    addLesson("Αλγόριθμοι και πολυπλοκότητα", 0, "5", "[421]", vbox1);
    addLesson("Αρχιτεκτονική II", 0, "5", "[422]", vbox1);
    addLesson("Ανάλυση και σχεδιασμός Π.Σ.", 0, "5", "[425]", vbox1);
    addLesson("Θεωρία συστημάτων - ΣΑΕ", 0, "5", "[426]", vbox1);
    addLesson("Δίκτυα II", 0, "5", "[427]", vbox1);
    gtk_box_pack_start (GTK_BOX(vbox1), gtk_hseparator_new(), FALSE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("1 από τα 2"), FALSE, FALSE, 5);
    addLesson("Υπολογισιμότητα", 1, "5", "[423]", vbox1);
    addLesson("Αρχές γλωσσών προγραμματισμού", 1, "5", "[424]", vbox1);

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);

    /* PEMPTO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("5o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    addLesson("Οικονομικά των επιχειρήσεων", 0, "5", "[920]", vbox1);

    if (kateuth == 0) {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση πληροφορικής"), FALSE, FALSE, 5);
        addLesson("Προγραμματισμός III", 0, "7", "[531Π]", vbox1);
        addLesson("Τεχνολογία λογισμικού", 0, "7", "[532Π]", vbox1);
        addLesson("Βάσεις δεδομένων II", 0, "6", "[533Π]", vbox1);
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("1 από τα 2"), FALSE, FALSE, 5);
        addLesson("Λογικός προγραμματισμός", 1, "5", "[534Π]", vbox1);
        addLesson("Οργάνωση και διαχείριση αρχείων ", 1, "5", "[535Π]", vbox1);
    } else {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση τηλεπικοινωνιών και δικτύων"), FALSE, FALSE, 5);
        addLesson("Επεξεργασία σήματος", 0, "7", "[541Τ]", vbox1);
        addLesson("Τηλεπικοινωνιακά συστήματα I", 0, "7", "[542Τ]", vbox1);
        addLesson("Οπτικές επικοινωνίες", 0, "6", "[543Τ]", vbox1);
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("1 από τα 2"), FALSE, FALSE, 5);
        addLesson("Κινητές επικοινωνίες", 1, "5", "[544Τ]", vbox1);
        addLesson("Σχεδίαση, μελέτη και υλοποίηση δικτύων", 1, "5", "[545Τ]", vbox1);
    }

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);


    /* ΕΚΤΟ EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("6o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("ΔΟΝΑ"), FALSE, FALSE, 5);
    addLesson("Τεχνική νομοθεσία", 0, "5", "[921]", vbox1);
    gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("1 από τα 2"), FALSE, FALSE, 5);
    addLesson("Επιχειρησιακή έρευνα", 1, "5", "[930]", vbox1);
    addLesson("Διαχείριση έργων πληροφορικής", 1, "5", "[931]", vbox1);

    if (kateuth == 0) {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση πληροφορικής  (4 από τα 6)"), FALSE, FALSE, 5);
        addLesson("Τεχνητή νοημοσύνη", 1, "5", "[631Π]", vbox1);
        addLesson("Προχωρημένες εφαρμογές προγραμματισμού", 1, "5", "[632Π]", vbox1);
        addLesson("Πολυμέσα", 1, "5", "[633Π]", vbox1);
        addLesson("Λειτουργικά συστήματα II", 1, "5", "[634Π]", vbox1);
        addLesson("Δικτυακός προγραμματισμός", 1, "5", "[655]", vbox1);
        addLesson("Ασφάλεια πληροφοριακών συστημάτων", 1, "5", "[656]", vbox1);
    } else {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση τηλεπικοινωνιών και δικτύων  (4 από τα 6)"), FALSE, FALSE, 5);
        addLesson("Επικοινωνίες δεδομένων", 1, "5", "[641Τ]", vbox1);
        addLesson("Τηλεπικοινωνιακά συστήματα II", 1, "5", "[642Τ]", vbox1);
        addLesson("Ειδικά θέματα οπτικών επικοινωνιών", 1, "5", "[643Τ]", vbox1);
        addLesson("Ασύρματες επικοινωνίες", 1, "5", "[644Τ]", vbox1);
        addLesson("Δικτυακός προγραμματισμός", 1, "5", "[655]", vbox1);
        addLesson("Ασφάλεια πληροφοριακών συστημάτων", 1, "5", "[656]", vbox1);
    }

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);

    /* EBDOMO EKSAMINO */
    vbox1 = gtk_vbox_new (FALSE, 5);
    exp = addTitle("7o εξάμηνο");
    gtk_container_add (GTK_CONTAINER (exp), vbox1);

    gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("ΔΟΝΑ  (1 από τα 2)"), FALSE, FALSE, 5);
    addLesson("Μάρκετινγκ πληροφοριακών συστημάτων", 1, "3", "[922]", vbox1);
    addLesson("Διδακτική της πληροφορικής", 1, "3", "[923]", vbox1);

    if (kateuth == 0) {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση πληροφορικής"), FALSE, FALSE, 5);
        addLesson("Σεμινάριο θεμάτων τεχνολογικής αιχμής", 0, "6", "[731Π]", vbox1);
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("3 από τα 6"), FALSE, FALSE, 5);
        addLesson("Ειδικά θέματα βάσεων δεδομένων", 1, "7", "[732Π]", vbox1);
        addLesson("Ηλεκτρονικό εμπόριο", 1, "7", "[733Π]", vbox1);
        addLesson("Προγραμματισμός Ιντερνετ", 1, "7", "[734Π]", vbox1);
        addLesson("Υπολογιστικό πλέγμα", 1, "7", "[735Π]", vbox1);
        addLesson("Μεταγλωττιστές", 1, "7", "[736Π]", vbox1);
        addLesson("Κατανεμημένα συστήματα", 1, "7", "[757]", vbox1);
    } else {
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("Κατεύθυνση τηλεπικοινωνιών και δικτύων"), FALSE, FALSE, 5);
        addLesson("Σεμινάριο θεμάτων τεχνολογικής αιχμής", 0, "6", "[741Τ]", vbox1);
        gtk_box_pack_start (GTK_BOX(vbox1), gtk_label_new("3 από τα 6"), FALSE, FALSE, 5);
        addLesson("Δορυφορικές επικοινωνίες", 1, "7", "[742Τ]", vbox1);
        addLesson("CDMA", 1, "7", "[743Τ]", vbox1);
        addLesson("Δικτύωση και αυτοματοποίηση", 1, "7", "[744Τ]", vbox1);
        addLesson("Ευρυζωνικά δίκτυα", 1, "7", "[745Τ]", vbox1);
        addLesson("Απόδοση δικτύων", 1, "7", "[746Τ]", vbox1);
        addLesson("Κατανεμημένα συστήματα", 1, "7", "[757]", vbox1);
    }

    gtk_box_pack_start (GTK_BOX(vbox), exp, FALSE, FALSE, 0);
    addLesson("Πτυχιακή εργασία", 0, "20", "[801]", vbox);

    gtk_box_pack_start (GTK_BOX(vbox), addButtons(), FALSE, FALSE, 5);

    gtk_container_add (GTK_CONTAINER (main_window), vbox);

    gtk_widget_show_all (main_window);

    gtk_main ();
    return 0;
}

GtkWidget *addTitle(gchar *temp)
{
    GtkWidget *exp = gtk_expander_new (temp);
    gtk_expander_set_spacing(GTK_EXPANDER(exp), 5);
    return exp;
}

void addLesson(gchar *title, gint flag, char dmon[], gchar *code, GtkWidget *eksam)
{
    GtkWidget *hbox;
    hbox = gtk_hbox_new (FALSE, 5);

    /* DIDAKTIKES MONADES MATHIMATOS */
    lessons[i].DM = atoi(dmon);
    gtk_box_pack_end (GTK_BOX(hbox), gtk_label_new(dmon), FALSE, FALSE, 5);

    /* BATHMOS */
    lessons[i].entry = gtk_entry_new();
    gtk_entry_set_width_chars (GTK_ENTRY(lessons[i].entry), 5);
    gtk_entry_set_max_length (GTK_ENTRY(lessons[i].entry), 5);
    gtk_entry_set_text (GTK_ENTRY(lessons[i].entry), "5");
    gtk_box_pack_end (GTK_BOX(hbox), lessons[i].entry, FALSE, FALSE, 0);

    /* CHECK BOX */
    lessons[i].checkbtn = gtk_check_button_new();
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(lessons[i].checkbtn), TRUE);
    gtk_widget_show (lessons[i].checkbtn);
    if (flag == 0) {
        gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(lessons[i].checkbtn), TRUE);
        gtk_widget_set_sensitive (GTK_WIDGET(lessons[i].checkbtn), FALSE);
        gtk_widget_hide (lessons[i].checkbtn);
    }
    gtk_box_pack_start (GTK_BOX(hbox), lessons[i].checkbtn, FALSE, FALSE, 0);

    /* KODIKOS MATHIMATOS */
    lessons[i].code = gtk_label_new(code);
    gtk_box_pack_start (GTK_BOX(hbox), lessons[i].code, FALSE, FALSE, 0);

    /* TITLOS MATHIMATOS */
    lessons[i].title = gtk_label_new(title);
    gtk_box_pack_start (GTK_BOX(hbox), lessons[i].title, FALSE, FALSE, 5);

    g_signal_connect (G_OBJECT(lessons[i].checkbtn), "toggled", G_CALLBACK (checkbtnToggle), GINT_TO_POINTER(i));

    gtk_box_pack_start (GTK_BOX(eksam), hbox, TRUE, FALSE, 0);

    i++;
}

void checkbtnToggle(GtkWidget *self, gint temp)
{
    if ( gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(lessons[temp].checkbtn))) {
        gtk_widget_set_sensitive (GTK_WIDGET(lessons[temp].entry), TRUE);
        i++;
    } else {
        gtk_widget_set_sensitive (lessons[temp].entry, FALSE);
        i--;
    }
}

gint epilogiKate(void)
{
    gint temp=0;
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new (NULL, 0,  GTK_MESSAGE_QUESTION, GTK_BUTTONS_NONE, "Επιλέξτε την κατεύθυνση που ακολουθείτε");
    gtk_dialog_add_buttons (GTK_DIALOG (dialog), "Πληροφορικής", 0, "Τηλεπικοινωνιών και δικτύων", 1, NULL);
    gtk_window_set_title(GTK_WINDOW (dialog), "Επιλογή κατεύθυνσης");
    temp = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy (dialog);
    return temp;
}

GtkWidget *addButtons()
{
    GtkWidget *hbox, *button;

    hbox = gtk_hbox_new (FALSE, 5);

    button = gtk_button_new_with_label ("Υπολογισμός");
    gtk_button_set_image(GTK_BUTTON(button), gtk_image_new_from_stock(GTK_STOCK_EDIT, GTK_ICON_SIZE_BUTTON));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (calculate), NULL);
    gtk_box_pack_start (GTK_BOX(hbox), button, TRUE, FALSE, 5);

    button = gtk_button_new_from_stock(GTK_STOCK_ABOUT);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (aboutClicked), NULL);
    gtk_box_pack_start (GTK_BOX(hbox), button, TRUE, FALSE, 5);

    button = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtk_main_quit), NULL);
    gtk_box_pack_start (GTK_BOX(hbox), button, TRUE, FALSE, 5);

    return hbox;

}

void calculate()
{
    GtkWidget *dialog = gtk_dialog_new();
    float mo=0, temp;
    int k = 0, j = 0;
    struct lesson less[LESSONS_PER_DIR];

    while ( j < LESSONS_PER_DIR) {
        if (gtk_widget_get_sensitive(lessons[j].entry) == TRUE) {
            less[k].title = lessons[j].title;
            less[k].DM = lessons[j].DM;
            less[k].checkbtn = lessons[j].checkbtn;
            less[k].entry = lessons[j].entry;
            k++;
        }
        j++;
    }

    if (i != LESSONS_TO_END) {
        dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0,  GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Λάθος αριθμός μαθημάτων. Ελέγξτε ξανά το πλήθος των μαθημάτων επιλογής.");
        gtk_dialog_run(GTK_DIALOG(dialog));
    } else {
        if (checkTable(less) == 0) {
            for (k=0; k<i; k++) {
                temp = atof(gtk_entry_get_text(GTK_ENTRY(less[k].entry)));
                mo += (float) less[k].DM * temp / 230; /* sinolo didaktikwn monadwn : 230 */
            }
            dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0,  GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Ο βαθμός του πτυχίου σου είναι %2.2f", mo);
            gtk_dialog_run(GTK_DIALOG(dialog));
        }
    }
    gtk_widget_destroy (dialog);
}

void aboutClicked()
{
    GtkWidget *dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "Βαθμός πτυχίου!");
//    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "1.0");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Βασιλάκος Γεώργιος");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
                                  "Υπολογίζει το βαθμό πτυχίου σύμφωνα με το νέο πρόγραμμα σπουδών (>2005Χ) του Τμήματος Τεχνολογίας Πληροφορικής και Τηλεπικοινωνιών ΤΕΙ Λάρισας.");
    gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog),  gdk_pixbuf_new_from_xpm_data((const char **) icon()));
    gtk_dialog_run(GTK_DIALOG (dialog));
    gtk_widget_destroy(dialog);
}

int checkTable(struct lesson less[LESSONS_PER_DIR])
{
    GtkWidget *dialog;
    float temp;
    int k, j, sum = 0;

    if (gtk_widget_get_sensitive (lessons[23].entry) == gtk_widget_get_sensitive (lessons[24].entry) ) {
        dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Ελέγξτε ξανά τα μαθήματα επιλογής του 4ου εξαμήνου.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy (dialog);
        return 1;
    }
    if (gtk_widget_get_sensitive (lessons[29].entry) == gtk_widget_get_sensitive (lessons[30].entry) ) {
        dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Ελέγξτε ξανά τα μαθήματα επιλογής του 5ου εξαμήνου.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy (dialog);
        return 1;
    }

    for (sum=0, j=34; j<=39; j++)
        if (gtk_widget_get_sensitive(lessons[j].entry) == TRUE)
            sum++;

    if (sum != 4 || gtk_widget_get_sensitive (lessons[32].entry) == gtk_widget_get_sensitive (lessons[33].entry)) {
        dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Ελέγξτε ξανά τα μαθήματα επιλογής του 6ου εξαμήνου.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy (dialog);
        return 1;
    }

    for (sum=0, j=43; j<=48; j++)
        if (gtk_widget_get_sensitive (lessons[j].entry) == TRUE)
            sum++;

    if (sum != 3 || gtk_widget_get_sensitive(lessons[40].entry) == gtk_widget_get_sensitive (lessons[41].entry)) {
        dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Ελέγξτε ξανά τα μαθήματα επιλογής του 7ου εξαμήνου.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy (dialog);
        return 1;
    }

    for (k=0; k<LESSONS_TO_END; k++) {
        temp = strtof(gtk_entry_get_text(GTK_ENTRY(less[k].entry)), NULL);
        if (temp < 5 || temp > 10) {
            dialog = gtk_message_dialog_new (GTK_WINDOW(main_window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Λάθος εισαγωγή στο μάθημα %s.", gtk_label_get_text(GTK_LABEL(less[k].title)));
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy (dialog);
            return 1;
        }
    }
    return 0;
}

char **icon(){
static char *pixmap[] = {
/* columns rows colors chars-per-pixel */
"32 32 2 1",
". c #000000",
"  c None",
/* pixels */
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"            .......             ",
"         ...............        ",
"      ......................    ",
"   .............................",
"............................... ",
".............................   ",
"   .......................      ",
"       ....  ......  ... .      ",
"         .....     ....  .      ",
"         ..............  ..     ",
"         ..............   .     ",
"         ..............   ..    ",
"           .....           .    ",
"            ..                  ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                "
};

return pixmap;
}