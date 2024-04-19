#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct admin
{
    char username[20];
    char password[20];
} admin;

struct seller
{
    char username[20];
    char password[20];
    char email[20];
    char nomor_telepon[20];
    char jasa[30];
    int jumlah;
    int harga;
    char keterangan[50];
    char nama[30];
    char feedback[20];
    char laporan[100];
    char customer[20];
    char status[20];
} data_seller, selleraktif;

struct customer
{
    char username[20];
    char password[20];
    char email[20];
    char nomor_telepon[20];
    char feedback[20];
    int saldo;
    int frekuensi, pengeluaran;
    char status[20];
    char laporan[50];
    char pengirim[20];
    char seller[20];
} data, useraktif;

struct feedback_customer_seller
{
    char customer_username[20];
    char seller_username[20];
    char feedback[50];
};

struct pesan{
    char nama[30], jasa[20], harga[20],metode[20],nomor_telepon[20],email[20];
    int jumlah;
}pesan;  


int loginadmin(int attempt);
int loginseller(int attempt);
int logincustomer(int attempt);
void registrasi_customer();
void registrasi_seller();
void menu_registrasi();
void menucustomer();
void menuadmin();
void menuseller();
void saldo();
void menu_hapus_akun();
void hapus_akun_customer();
void hapus_akun_seller();
void menambahkan_jasa();
void marketplace();
void feedback();
void lihat_feedback();
void cekstatus();
void laporan_customer();
void laporan_seller();
void laporan();
void lihat_laporan_customer();
void lihat_laporan_seller();
void history();
void kode();
void menu_informasi_akun();
void informasi_akun_customer();
void informasi_akun_seller();
void menu_bahasa();
// void english();

int main()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------ Indolance -------------------------\n");
    printf("============================================================\n");
    printf("1.Admin Login\n2.Account Registration\n3.Seller Login\n4.Customer Login\n5.Exit\n");
    printf("Choose Menu (1/2/3/4/5) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        loginadmin(3);
        menuadmin();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        menu_registrasi();
        break;

    case 3:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        loginseller(3);
        menuseller();
        break;

    case 4:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        logincustomer(3);
        menucustomer();
        break;

    case 5:
        printf("Exiting the program. Goodbye!\n");
        break;

    default:
        printf("Sorry your option is unavailable\n");
        main();
        break;
    }
    return 0;
}

int loginadmin(int attempt)
{
    printf("Enter Username : ");
    gets(admin.username);
    printf("Enter Password : ");
    gets(admin.password);
    system("cls");

    if (strcmp(admin.username, "admin") == 0 && strcmp(admin.password, "admin123") == 0)
    {
        printf("Welcome Admin\n");
        return 1;
    }
    else
    {
        attempt--;
    }

    if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username or Password incorrect. Attempt left %d \n", attempt);
        loginadmin(attempt);
    }
    else
    {
        printf("Your 3 attempts is incorrect\n");
        system("pause");
        system("cls");
        main();
    }
}

void menu_registrasi()
{
    int menu;

    printf("1.Seller Registration\n2.Customer Registrasi\n3.Exit\n");
    printf("Choose Menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        registrasi_seller();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        registrasi_customer();
        break;

    case 3:
        main();
        break;

    default:
        printf("Sorry your option is unavailable\n");
        main();
        break;
    }
}

int logincustomer(int attempt)
{
    FILE *akun_customer;
    struct customer data;

    akun_customer = fopen("akun_customer.dat", "rb");

    char username[50], password[50];

    printf("Enter Username : ");
    gets(username);
    printf("Enter Password : ");
    gets(password);

    while (fread(&data, sizeof(data), 1, akun_customer) == 1)
    {
        if (strcmp(data.username, username) == 0 && strcmp(data.password, password) == 0)
        {
            useraktif = data;
            fclose(akun_customer);
            system("cls");
            attempt = -1;
            break;
        }
        else
        {
            attempt--;
        }
    }

    if (attempt == -1)
    {
        kode();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username or Password incorrect. Attempt left %d \n", attempt);
        fclose(akun_customer);
        logincustomer(attempt);
    }
    else
    {
        printf("Your 3 attempts is incorrect \n");
        system("pause");
        system("cls");
        fclose(akun_customer);
        main();
    }
}

int loginseller(int attempt)
{
    FILE *akun_seller;
    struct seller data_seller;

    akun_seller = fopen("akun_seller.dat", "rb");

    char username[50], password[50];

    printf("Enter Username : ");
    gets(username);

    while (fread(&data_seller, sizeof(data_seller), 1, akun_seller) == 1)
    {
        if (strcmp(data_seller.username, username) == 0)
        {
            printf("Enter Password : ");
            gets(password);
            if (strcmp(data_seller.password, password) == 0)
            {
                selleraktif = data_seller;
                fclose(akun_seller);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }

    if (attempt == -1)
    {
        menuseller();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username or Password incorrect. Attempt left %d \n", attempt);
        fclose(akun_seller);
        loginseller(attempt);
    }
    else
    {
        printf("Your 3 attempts is incorrect \n");
        system("pause");
        system("cls");
        fclose(akun_seller);
        main();
    }
}

void menuadmin()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ Menu Admin -------------------------\n");
    printf("=============================================================\n");
    printf("1. Check Report\n");
    printf("2. Account Deletion\n");
    printf("3. Account Information \n");
    printf("4. History\n");
    printf("5. Logout\n");
    printf("Choose Menu (1/2/3/4/5): ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        laporan();
        break;

    case 2:
        menu_hapus_akun();
        break;

    case 3:
        menu_informasi_akun();
        break;

    case 4:
        history();
        break;

    case 5:
        printf("Logout Successful.\n");
        system("pause");
        system("cls");
        main();
        break;

    default:
        printf("Sorry your option is unavailable\n");
        break;
    }
}

void menucustomer()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("1.Balance Information\n2.Marketplace\n3.Order Status\n4.Feedback\n5.Report\n6.Log out\n");
    printf("Choose menu (1/2/3/4/5): ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    switch (menu)
    {
    case 1:
        saldo();
        break;
    case 2:
        marketplace();
        break;
    case 3:
        cekstatus();
        break;
    case 4:
        feedback();
        break;
    case 5:
        laporan_customer();
        break;
    case 6:
        printf("Logout Successful\n");
        system("pause");
        system("cls");
        main();
    default:
        printf("Sorry your option is unavailable\n");
        exit(0);
        break;
    }
}

void menuseller()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("1.Add Service\n2.Update Status\n3.Earnings\n4.Report\n5.Order\n6.Feedback\n7.Logout\n");
    printf("Pilih menu (1/2/3/4/5/6/7): ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    switch (menu)
    {
    case 1:
        menambahkan_jasa();
        break;
    case 2:
        // update_status();
        break;
    case 3:
        // penghasilan();
        break;
    case 4:
        laporan_seller();
        break;
    case 5:
        // pesanan();
        break;
    case 6:
        lihat_feedback();
    case 7:
        printf("Logout Successful\n");
        system("pause");
        system("cls");
        main();
    default:
        printf("Sorry your option is unavailable\n");
        exit(0);
        break;
    }
}

void menu_bahasa()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("1.Bahasa Indonesia\n2.English\n");
    printf("Pilih menu (1/2)");
    scanf("%d",&menu);
    getchar();

    switch(menu)
    {
        case 1:
        system("cls");
        menucustomer();
        break;
        case 2:
        // english();
        break;
        default:
        printf("Your statement not defined");
        break;
    }

}

void registrasi_customer()
{
    FILE *akun;
    struct customer baru = {0};

    strcpy(baru.status, "No Orders\n");

    akun = fopen("akun_customer.dat", "ab");

    printf("Enter Username : ");
    gets(baru.username);
    printf("Enter Password : ");
    gets(baru.password);
    printf("Enter Email: ");
    gets(baru.email);
    printf("Enter Phone Number: ");
    gets(baru.nomor_telepon);
    strcpy(data.status, "No Order");
    data.saldo = 0;
    data.frekuensi = 0;
    data.pengeluaran = 0;
    printf("Registration Successful. Please Login\n");

    fwrite(&baru, sizeof(baru), 1, akun);
    fclose(akun);
    system("pause");
    system("cls");
    main();
}

void registrasi_seller()
{
    FILE *akun;
    struct seller new_seller = {0};

    akun = fopen("akun_seller.dat", "ab");

    printf("Enter Username : ");
    gets(new_seller.username);
    printf("Enter Password : ");
    gets(new_seller.password);
    printf("Enter Email : ");
    gets(new_seller.email);
    printf("Enter Phone Number : ");
    gets(new_seller.nomor_telepon);

    fwrite(&new_seller, sizeof(new_seller), 1, akun);
    fclose(akun);

    printf("Registration Successful. Please Login\n");
    system("pause");
    system("cls");
    main();
}

void saldo()
{
    int jumlah;
    int pilihan;
    int hasilTopUp = 0;
    FILE *akun;
    FILE *akun2;

    printf("========================= Menu Saldo ========================\n");
    printf("1. Check Balance\n");
    printf("2. Balance Top Up\n");
    printf("3. Return to Customer Menu\n");
    printf("Choose menu (1/2/3) : ");
    scanf("%d", &pilihan);
    system("cls");
    switch (pilihan)
    {
    case 1:
        akun = fopen("akun_customer.dat", "rb");
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        while (fread(&data, sizeof(data), 1, akun) == 1)
        {
            if (strcmp(data.username, useraktif.username) == 0)
            {
                printf("Your Balance: Rp %d\n", data.saldo);
            }
        }
        system("pause");
        system("cls");
        fclose(akun);
        saldo();
        break;

    case 2:
        hasilTopUp = useraktif.saldo;
        akun = fopen("akun_customer.dat", "rb");
        akun2 = fopen("akun_customer2.dat", "wb");

        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Enter your preferred balance top up : Rp ");
        scanf("%d", &jumlah);
        hasilTopUp = data.saldo + jumlah;
        while (fread(&data, sizeof(data), 1, akun) == 1)
        {
            if (strcmp(data.username, useraktif.username) == 0)
            {
                data.saldo = hasilTopUp;
            }
            fwrite(&data, sizeof(data), 1, akun2);
        }
        printf("Topup Successful. Current Balance : Rp %d\n", hasilTopUp);
        fclose(akun);
        fclose(akun2);

        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");

        system("pause");
        system("cls");
        menucustomer();
        break;

    case 3:
        fclose(akun);
        menucustomer();
        break;

    default:
        printf("Option invalid. Try again.\n");
        saldo();
        break;
    }
}

void menu_hapus_akun()
{
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    int menu;

    printf("1.Delete Seller Account\n2.Delete Customer Account\n3.Exit\n");
    printf("Choose Menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        hapus_akun_seller();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        hapus_akun_customer();
        break;

    case 3:
        menuadmin();
        break;

    default:
        printf("Sorry your option is unavailable\n");
        main();
        break;
    }
}

void hapus_akun_customer()
{
    FILE *file;
    struct seller seller_data;

    file = fopen("akun_customer.dat", "rb");

    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    printf("Customer Data:\n");
    while (fread(&data, sizeof(data), 1, file) == 1)
    {
        printf("Username: %s\n", data.username);
        printf("Password: %s\n", data.password);
        printf("\n");
    }

    // Menutup file setelah selesai membacanya
    fclose(file);

    FILE *akun;
    FILE *akun2;
    char dicari[20];

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    printf("Enter Username for Deletion : ");
    gets(dicari);

    int akun_ditemukan = 0;

    while (fread(&data, sizeof(data), 1, akun) == 1)
    {
        if (strcmp(data.username, dicari) == 0)
        {
            akun_ditemukan = 1;
        }
        else
        {
            fwrite(&data, sizeof(data), 1, akun2);
        }
    }

    fclose(akun);
    fclose(akun2);

    if (akun_ditemukan)
    {
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Account with username '%s' successfully deleted.\n", dicari);
    }
    else
    {
        printf("Account with username '%s' couldn't be found.\n", dicari);
    }

    system("pause");
    system("cls");
    menuadmin();
}

void hapus_akun_seller()
{
    FILE *file;
    struct seller seller_data;

    // Membuka file untuk dibaca dalam mode binary
    file = fopen("akun_seller.dat", "rb");

    // Memeriksa apakah file berhasil dibuka
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }


    printf("Data Akun Seller:\n");
    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        printf("Username: %s\n", seller_data.username);
        printf("Password: %s\n", seller_data.password);
        printf("\n");
    }


    fclose(file);

    FILE *akun;
    FILE *akun2;
    char dicari[20];

    akun = fopen("akun_seller.dat", "rb");
    akun2 = fopen("akun_seller2.dat", "wb");

    printf("Enter Username for Deletion : ");
    gets(dicari);

    int akun_ditemukan = 0;

    while (fread(&data_seller, sizeof(data_seller), 1, akun) == 1)
    {
        if (strcmp(data_seller.username, dicari) == 0)
        {
            akun_ditemukan = 1;
        }
        else
        {
            fwrite(&data_seller, sizeof(data_seller), 1, akun2);
        }
    }

    fclose(akun);
    fclose(akun2);

    if (akun_ditemukan)
    {
        remove("akun_seller.dat");
        rename("akun_seller2.dat", "akun_seller.dat");
        printf("Account with username '%s' successfully deleted.\n", dicari);
    }
    else
    {
        printf("Account with username '%s' couldn't be found.\n", dicari);
    }

    system("pause");
    system("cls");
    menuadmin();
}

void menu_informasi_akun()
{
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    int menu;

    printf("1.Customer Account Information\n2.Seller Account Information\n3.Exit\n");
    printf("Choose menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        informasi_akun_customer();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        informasi_akun_seller();
        break;

    case 3:
        menuadmin();
        break;

    default:
        printf("Sorry your option is unavailable\n");
        main();
        break;
    }
}

void informasi_akun_customer()
{
    
    FILE *file;
    struct seller seller_data;

    file = fopen("akun_customer.dat", "rb");

    if (file == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    printf("Customer Account Data:\n");
    while (fread(&data, sizeof(data), 1, file) == 1)
    {
        printf("Username: %s\n", data.username);
        printf("Password: %s\n", data.password);
        printf("Phone Number : %s\n", data.nomor_telepon);
        printf("Email: %s\n",data.email);
        printf("\n");
    }

    fclose(file);
}

void informasi_akun_seller()
{
    FILE *file;
    struct seller seller_data;

    // Membuka file untuk dibaca dalam mode binary
    file = fopen("akun_seller.dat", "rb");

    // Memeriksa apakah file berhasil dibuka
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    // Membaca data dari file dan menampilkannya
    printf("Seller Account Data:\n");
    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        printf("Username: %s\n", seller_data.username);
        printf("Password: %s\n", seller_data.password);
        printf("Phone Number : %s\n", seller_data.nomor_telepon);
        printf("Email: %s\n",seller_data.email);
        printf("\n");
    }

    // Menutup file setelah selesai membacanya
    fclose(file);
}

void menambahkan_jasa()
{
    FILE *jasa;
    struct seller baru = {0};

    jasa = fopen("jasa.dat", "ab+");

    printf("Enter Store Name: ");
    gets(baru.nama);
    printf("Enter Service: ");
    gets(baru.jasa);
    printf("Enter Status: ");
    gets(baru.status);
    printf("Enter Description: ");
    gets(baru.keterangan);
    printf("Enter Price: ");
    scanf("%d", &baru.harga);
    getchar();

    fwrite(&baru, sizeof(baru), 1, jasa);
    fclose(jasa);

    printf("Service has been successfully added\n");
    system("pause");
    system("cls");
    menuseller();
}

void marketplace()
{
    FILE *file;
    FILE *data_pesanan;
    char dicari[20];
    int menu,harga,total_harga;
    struct seller seller_data;

    file = fopen("jasa.dat", "rb+");

    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    printf("Marketplace:\n");
    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        printf("Store Name   : %s\n", seller_data.nama);
        printf("Service      : %s\n", seller_data.jasa);
        printf("Status       : %s\n", seller_data.status);
        printf("Description  : %s\n", seller_data.keterangan);
        printf("Price        : %d\n", seller_data.harga);
        printf("\n");
    }

    fclose(file);

    printf("Choose a service: ");
    gets(dicari);

    file = fopen("jasa.dat","rb+");

    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        if (strcmp(seller_data.jasa, dicari)==0 )
        {
            harga = seller_data.harga;
            strcpy(seller_data.status, "Ordered");
            break;
        }
    }

    data_pesanan = fopen("data pesanan.dat", "wb");
    
    printf("Client Name\t: "); 
    gets(pesan.nama);
    printf("Total Order\t: "); 
    scanf("%d",&pesan.jumlah);
    getchar();
    printf("Phone Numbern\t: ");
    gets(pesan.nomor_telepon);
    printf("Email\t: ");
    gets(pesan.email);

    fwrite(&pesan,sizeof(pesan),1,data_pesanan);
    fclose(data_pesanan);



    total_harga = harga * pesan.jumlah;
    printf("Total Price : %d \n",total_harga);

    printf("=============================================\n");
    printf("Choose Payment Option \n");
    printf("1.Balance\n2.Transfer\n");
    printf("Choose Payment Option : ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
        printf("============================================================\n");
        printf("------------------------ D'LAUNDRY -------------------------\n");
        printf("============================================================\n");
        FILE *akun;
        FILE *akun2;
        akun = fopen("akun_customer.dat", "rb");
        akun2 = fopen("akun_customer2.dat", "wb");

        harga = seller_data.harga;

        if (harga > useraktif.saldo)
            {
            printf("Sorry your balance insufficient\n");
            fclose(akun);
            fclose(akun2);
            system("pause");
            system("cls");
            menucustomer();
        }
        else
        {
            while (fread(&data, sizeof(data), 1, akun) == 1)
            {
                if (strcmp(useraktif.username, data.username) == 0)
                {
                    data.saldo -= harga;
                    data.pengeluaran += harga;
                    data.frekuensi += 1;
                }
                fwrite(&data, sizeof(data), 1, akun2);
            }
            fclose(akun);
            fclose(akun2);

            remove("akun_customer.dat");
            rename("akun_customer2.dat", "akun_customer.dat");

            printf("Setor Berhasil\n");
            system("pause");
            system("cls");
            menucustomer();
            break;
        }
        break;
        case 2:
        printf(""); //nomer rekening
        break;
    }

}

void feedback()
{
    FILE *file;
    struct feedback_customer_seller feedback_data;

    file = fopen("feedback.dat", "ab"); // Buka file feedback untuk ditulis dalam mode append binary

    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char seller_tujuan[20];
    printf("Enter Seller username for Feedback: ");
    gets(seller_tujuan);

    printf("Enter Comment: ");
    gets(feedback_data.feedback);

    strcpy(feedback_data.customer_username, useraktif.username);
    strcpy(feedback_data.seller_username, seller_tujuan);
    fwrite(&feedback_data, sizeof(feedback_data), 1, file);
    fclose(file);

    printf("Feedback has been sent\n");

    system("pause");
    system("cls");
    menucustomer();
}

void lihat_feedback()
{
    FILE *file;
    struct feedback_customer_seller feedback_data;

    file = fopen("feedback.dat", "rb");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    printf("============================================================\n");
    printf("----------------------Customer Feedback --------------------\n");
    printf("============================================================\n");

    while (fread(&feedback_data, sizeof(feedback_data), 1, file) == 1)
    {
        if (strcmp(feedback_data.seller_username, selleraktif.username) == 0)
        {
            printf("Pembeli  : %s\n", feedback_data.customer_username);
            printf("Komentar : %s\n", feedback_data.feedback);
        }
    }

    fclose(file);

    system("pause");
    system("cls");
    menuseller();
}

void cekstatus()
{
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("Order Status : %s", useraktif.status);
    system("pause");
    system("cls");
    menucustomer();
}

void laporan_customer()
{
    FILE *file;
    file = fopen("laporan_customer.dat", "ab");

    printf("==============================================================\n");
    printf("------------------------- INDOLANCE --------------------------\n");
    printf("==============================================================\n");
    printf("Enter name          : ");
    gets(data.username);

    printf("Enter seller name   : ");
    gets(data.seller);

    printf("Enter comment       : ");
    gets(data.laporan);

    fwrite(&data, sizeof(data), 1, file);

    fclose(file);

    printf("Comment Sent\n");
    system("pause");
    system("cls");
    menucustomer();
}

void laporan_seller()
{
    FILE *file;

    file = fopen("laporan_seller.dat", "ab");

    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");
    printf("MEnter Name          : ");
    gets(data_seller.username);

    printf("Enter Customer Name  : ");
    gets(data_seller.customer);

    printf("Enter Comment        : ");
    gets(data_seller.laporan);

    fwrite(&data_seller, sizeof(data_seller), 1, file);

    fclose(file);

    printf("Comment Sent\n");
    system("pause");
    system("cls");
    menucustomer();
}

void laporan()
{
    int menu;
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");
    printf("1.Customer Report\n2.Seller Report\n3.Return\n");
    printf("Choose menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        lihat_laporan_customer();
        break;
    case 2:
        lihat_laporan_seller();
        break;
    case 3:
        menuadmin();
        break;
    default:
        printf("Your option is unavailable");
        break;
    }
}

void lihat_laporan_customer()
{
    FILE *file;
    struct customer data;

    file = fopen("laporan_customer.dat", "rb");
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");

    while (fread(&data, sizeof(data), 1, file))
    {
        printf("Name               : %s\n", data.username);
        printf("Reported Account   : %s\n", data.seller);
        printf("Report             : %s\n", data.laporan);
        printf("-------------------------\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menuadmin();
}

void lihat_laporan_seller()
{
    FILE *file;
    struct seller data_seller;

    file = fopen("laporan_seller.dat", "rb");
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");

    while (fread(&data_seller, sizeof(data_seller), 1, file))
    {
        printf("Name               : %s\n", data_seller.username);
        printf("Reported Account   : %s\n", data_seller.customer);
        printf("Report             : %s\n", data_seller.laporan);
        printf("-------------------------\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menuadmin();
}

void history()
{
    FILE *akun;
    int i, j;
    struct customer temp, sorting[30];
    int count = 0;

    akun = fopen("akun_customer.dat", "rb");

    while (fread(&data, sizeof(data), 1, akun) == 1)
    {
        sorting[count] = data;
        count++;
    }

    fclose(akun);

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (sorting[j].frekuensi < sorting[j + 1].frekuensi)
            {
                temp = sorting[j];
                sorting[j] = sorting[j + 1];
                sorting[j + 1] = temp;
            }
        }
    }

    printf("========================= History =========================\n");
    for (i = 0; i < count; i++)
    {
        printf("Username       : %s\n", sorting[i].username);
        printf("Frequency      : %d\n", sorting[i].frekuensi);
        printf("Balance History: %d\n", sorting[i].pengeluaran);
        printf("============================================================\n");
    }
    system("pause");
    system("cls");
    menuadmin();
}

void kode() {
    char kode1[10], kode2[10], kode3[10];
    printf("\nEnter the code below\n");
    printf("---------------\n");
    printf("- Q.w.e.R.T.7 -\n");
    printf("---------------\n");
    printf("Enter Code : ");
    scanf("%s", &kode1);
    if (strcmp(kode1, "QweRT7") == 0) {
        system("cls");
        useraktif = data;
        printf("\n======================= Login Successful =====================\n");
        menu_bahasa();
    } else {
        system("cls");
        printf("\nEnter the new code below\n");
        printf("---------------\n");
        printf("- A.S.D.f.g.3 -\n");
        printf("---------------\n");
        printf("Enter Code : ");
        scanf("%s", &kode2);
        if (strcmp(kode2, "ASDfg3") == 0){
            system("cls");
            useraktif = data;
            printf("\n==================== Login Successful =======================\n");
            menu_bahasa();
        } else {
            system("cls");
            useraktif = data;
            printf("\nEnter the new code below\n");
            printf("---------------\n");
            printf("- Z.x.c.V.B.1 -\n");
            printf("---------------\n");
            printf("Enter Code : ");
            scanf("%s", &kode3);
            if (strcmp(kode3, "ZxcVB1") == 0){
                system("cls");
                useraktif = data;
                printf("\n========================= Login Successful ===================\n");
                menu_bahasa();
            } else {
                printf("Try Again Later\n");
                system("pause");
                system("cls");
                main();
            }
        }
    }
}