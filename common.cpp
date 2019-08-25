#include "common.h"

using namespace std;

void gotoxy (int x, int y ){
    COORD coord; // Mendeklarasikan kordinat
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void firstmenu(List_P &Lp, List_R &Lr, List_C &Lc){
    system("cls");
    int opt;

    do{
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "==================[ HOME ]===================" << endl << endl;
        cout << "            1. Login / Register" << endl;
        cout << "            2. Guest" << endl;
        cout << "            0. Exit" << endl << endl;
        cout << "=============================================" << endl;
        cout << "= Masukan pilihan anda : "; cin >> opt;
        switch(opt){
        case 1:
            loginmenu(Lp, Lr, Lc);
            break;
        case 2:
            guestmenu(Lp, Lr, Lc);
            break;
        }
    } while(opt != 0);
}

void loginmenu(List_P &Lp, List_R &Lr, List_C &Lc){
    system("cls");
    int opt;

    do{
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "================[ LOGIN MENU ]===============" << endl << endl;
        cout << "                1. Login" << endl;
        cout << "                2. Register" << endl;
        cout << "                0. Back" << endl << endl;
        cout << "=============================================" << endl;
        cout << "= Masukan pilihan anda : "; cin >> opt;
        switch(opt){
        case 1:
            optlogin(Lp, Lr, Lc);
            break;
        case 2:
            optregister(Lp, Lr, Lc);
            break;
        }
    } while(opt != 0);
    system("cls");
}

void optlogin(List_P &Lp, List_R &Lr, List_C &Lc){
    system("cls");
    infotype_C x;
    address_C AdrC;
    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "================[ LOGIN MENU ]===============" << endl << endl;
    cout << "     Username : "; cin >> x.uname; cout << endl;
    cout << "     Password : "; cin >> x.pword; cout << endl;
    AdrC = findaccount_C(Lc, x);
    if(x.uname == "admin" && x.pword == "admin"){
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "================[ LOGIN MENU ]===============" << endl << endl;
        cout << "    S E L A M A T D A T A N G K I N G S :)" << endl;
        getch();
        adminmenu(Lp, Lr, Lc);
    } else {
        if(AdrC != NULL){
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "================[ LOGIN MENU ]===============" << endl << endl;
            cout << "       S E L A M A T D A T A N G " << info(AdrC).uname << " :)" << endl;
            getch();
            usermenu(Lp, Lr, Lc, AdrC);
        } else {
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "================[ LOGIN MENU ]===============" << endl << endl;
            cout << "      Username atau password anda salah";
            getch();
        }
    }
    system("cls");
}

void optregister(List_P &Lp, List_R &Lr, List_C &Lc){
    system("cls");
    infotype_C x;
    address_C AdrC;

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "==============[ REGISTER MENU ]==============" << endl << endl;
    cout << "     Username      : "; cin >> x.uname;
    cout << "     Password      : "; cin >> x.pword;
    cout << "     Nama          : "; cin >> x.nama;
    cout << "     Jenis Kelamin : "; cin >> x.jk;
    cout << "     Tanggal Lahir : "; cin >> x.tgl;
    AdrC = findusername_C(Lc, x);
    if(x.uname != "admin"){
        if(AdrC == NULL){
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "==============[ REGISTER MENU ]==============" << endl << endl;
            cout << "            Pendaftaran berhasil";
            getch();
            insertcustomer_C(Lc, allocation_C(x));
        } else {
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "==============[ REGISTER MENU ]==============" << endl << endl;
            cout << "     Maaf username anda sudah terpakai" << endl;
            cout << "             Silahkan coba lagi";
            getch();
        }
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "==============[ REGISTER MENU ]==============" << endl << endl;
        cout << "     Maaf username anda sudah terpakai" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void adminmenu(List_P &Lp, List_R &Lr, List_C &Lc){
    system("cls");
    int opt;

    do{
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "================[ KINGS MENU ]===============" << endl << endl;
        cout << "             1. Insert Product" << endl;
        cout << "             2. Update Product" << endl;
        cout << "             3. Delete Product" << endl;
        cout << "             4. View Product" << endl;
        cout << "             5. View All Product" << endl;
        cout << "             6. View All Customer" << endl;
        cout << "             7. Delete Customer" << endl;
        cout << "             0. Logout" << endl << endl;
        cout << "=============================================" << endl;
        cout << "= Masukan pilihan anda : "; cin >> opt;
        switch(opt){
        case 1:
            insertproduct(Lp);
            break;
        case 2:
            updateproduct(Lp);
            break;
        case 3:
            deleteproduct(Lp, Lr);
            break;
        case 4:
            viewproduct(Lp,Lr,Lc);
            break;
        case 5:
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "========[ KINGS > LIHAT SEMUA PRODUK ]=======" << endl << endl;
            viewallproduct(Lp);
            getch();
            system("cls");
            break;
        case 6:
            viewallcustomer(Lc);
            break;
        case 7:
            deletecustomer(Lc, Lr);
            break;
        }
    } while(opt != 0);
}

void usermenu(List_P &Lp, List_R &Lr, List_C &Lc, address_C AdrC){
    system("cls");
    int opt;

    do{
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "================[ USER MENU ]================" << endl << endl;
        cout << "             1. Insert Rating" << endl;
        cout << "             2. Delete Rating" << endl;
        cout << "             3. Rating History" << endl;
        cout << "             4. Update Account" << endl;
        cout << "             0. Logout" << endl << endl;
        cout << "=============================================" << endl;
        cout << "= Masukan pilihan anda : "; cin >> opt;
        switch(opt){
        case 1:
            insertrating(Lr, Lp, AdrC);
            break;
        case 2:
            deleterelasi(Lr,Lp,AdrC);
            break;
        case 3:
            viewratinghistory(Lr, AdrC);
            break;
        case 4:
            updatecustomer(Lc, AdrC);
            break;
        }
    } while(opt != 0);
    system("cls");
}

void guestmenu(List_P Lp, List_R Lr, List_C Lc){
    system("cls");
    int opt;

    do{
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "================[ GUEST MENU ]===============" << endl << endl;
        cout << "             1. View Top 10 Product" << endl;
        cout << "             2. View All Product" << endl;
        cout << "             0. Back" << endl << endl;
        cout << "=============================================" << endl;
        cout << "= Masukan pilihan anda : "; cin >> opt;
        switch(opt){
        case 1:
            viewtopten(Lp);
            break;
        case 2:
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "========[ GUEST > LIHAT SEMUA PRODUK ]=======" << endl << endl;
            viewallproduct(Lp);
            getch();
            system("cls");
            break;
        }
    } while(opt != 0);
    system("cls");
}

void insertproduct(List_P &Lp){
    system("cls");
    infotype_P x;

    cin.ignore();

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ KINGS > TAMBAH PRODUK ]=========" << endl << endl;
    cout << "     Nama Produk   : "; getline(cin, x.namaprod);
    cout << "     Deskripsi     : "; getline(cin, x.deskprod);
    cout << "     Jumlah Barang : "; cin >> x.jumprod;
    cout << "     Harga         : "; cin >> x.harga;
    x.avgprod = 0;
    insertlast_P(Lp, allocation_P(x));
    system("cls");
}

void updateproduct(List_P &Lp){
    system("cls");
    string namaprod;
    address_P AdrP;

    cin.ignore();

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
    cout << "  Masukan nama produk yang akan diupdate : ";cin >> namaprod;
    AdrP = findproduct_P(Lp, namaprod);
    if(AdrP != NULL){
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "     Nama Produk   : "; getline(cin, info(AdrP).namaprod);getline(cin, info(AdrP).namaprod);
        cout << "     Deskripsi     : "; getline(cin, info(AdrP).deskprod);
        cout << "     Jumlah Barang : "; cin >> info(AdrP).jumprod;
        cout << "     Harga         : "; cin >> info(AdrP).harga;
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "         Produk anda berhasil diupdate";
        getch();
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void deleteproduct(List_P &Lp, List_R &Lr){
    system("cls");
    string namaprod;
    address_P AdrP;
    address_R AdrR;

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ KINGS > HAPUS PRODUK ]==========" << endl << endl;
    cout << "  Masukan nama produk yang akan di hapus : ";cin >> namaprod;
    AdrP = findproduct_P(Lp, namaprod);
    if (AdrP != NULL){
        if (AdrP == first(Lp)){
            deletefirst_P(Lp, AdrP);
            deleterelation_RP(Lr, AdrP, AdrR);
            deallocation_R(AdrR);
        } else if (AdrP == last(Lp)){
            deletelast_P(Lp, AdrP);
            deleterelation_RP(Lr, AdrP, AdrR);
            deallocation_R(AdrR);
        } else {
            deleteafter_P(Lp, AdrP);
            deleterelation_RP(Lr, AdrP, AdrR);
            deallocation_R(AdrR);
        }
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > HAPUS PRODUK ]==========" << endl << endl;
        cout << "         Produk anda berhasil dihapus";
        getch();
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void viewproduct(List_P &Lp, List_R &Lr, List_C &Lc){
    string namaprod;
    address_P AdrP;
    system("cls");

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ KINGS > LIHAT PRODUK ]==========" << endl << endl;
    cout << "  Masukan nama produk yang ingin dilihat : ";cin >> namaprod;
    AdrP = findproduct_P(Lp, namaprod);
    if(AdrP != NULL){
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > LIHAT PRODUK ]==========" << endl << endl;
        cout << "     Nama Produk   : " << info(AdrP).namaprod << endl;
        cout << "     Deskripsi     : " << info(AdrP).deskprod << endl;
        cout << "     Jumlah Barang : " << info(AdrP).jumprod << endl;
        cout << "     Harga         : " << info(AdrP).harga << endl;
        cout << "     Rata - rata   : " << info(AdrP).avgprod << endl << endl;
        cout << "==============[ RATING PRODUK ]==============" << endl << endl;
        viewrelation_R(Lr, AdrP);
        getch();
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void viewallproduct(List_P Lp){
    viewall_P(Lp);
}

void viewallcustomer(List_C Lc){
    system("cls");
    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "=========[ KINGS > LIHAT SEMUA USER ]========" << endl << endl;
    viewall_C(Lc);
    getch();
    system("cls");
}

void deletecustomer(List_C &Lc, List_R &Lr){
    infotype_C x;
    address_C AdrC;
    address_R AdrR;
    system("cls");

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "============[ KINGS > HAPUS USER ]===========" << endl << endl;
    cout << "  Masukan username yang akan dihapus : ";cin >> x.uname;
    AdrC = findusername_C(Lc, x);
    if (AdrC != NULL){
        if (AdrC == first(Lc)){
            deletefirst_C(Lc, AdrC);
            deleterelation_RC(Lr, AdrC, AdrR);
            deallocation_R(AdrR);
        } else if (AdrC == last(Lc)){
            deletelast_C(Lc, AdrC);
            deleterelation_RC(Lr, AdrC, AdrR);
            deallocation_R(AdrR);
        } else {
            deleteafter_C(Lc, AdrC);
            deleterelation_RC(Lr, AdrC, AdrR);
            deallocation_R(AdrR);
        }
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "============[ KINGS > HAPUS USER ]===========" << endl << endl;
        cout << "         User anda berhasil dihapus";
        getch();
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ KINGS > UPDATE PRODUK ]=========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void insertrating(List_R &Lr, List_P &Lp, address_C AdrC){
    system("cls");
    int rate;
    float AvgP;
    string namaprod;
    address_P AdrP;
    address_R AdrR;

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ USER > TAMBAH RATING ]==========" << endl << endl;
    cout << "  Masukan nama produk yang ingin dirating : ";cin >> namaprod;
    if(first(Lp) != NULL){
        AdrP = findproduct_P(Lp, namaprod);
        if(AdrP != NULL){
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > TAMBAH RATING ]==========" << endl << endl;
            cout << "               Produk ditemukan";
            getch();
            while(rate > 5){
                system("cls");
                cout << "================[ KING SHOP ]================" << endl;
                cout << "=                                           =" << endl;
                cout << "===========[ USER > TAMBAH RATING ]==========" << endl << endl;
                cout << "     Masukan Rating : "; cin >> rate;
            }
            AdrR = findrelation_R(Lr, AdrP, AdrC);
            if(AdrR != NULL){
                info(AdrR) = rate;
                AvgP = relationavg(Lr, AdrP);
                info(AdrP).avgprod = AvgP;
            } else {
                insertfirst_R(Lr,allocation_R(rate),AdrC,AdrP);
                AvgP = relationavg(Lr, AdrP);
                info(AdrP).avgprod = AvgP;
            }
        } else {
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > TAMBAH RATING ]==========" << endl << endl;
            cout << "     Maaf data yang anda cari tidak ada" << endl;
            cout << "             Silahkan coba lagi";
            getch();
        }
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ USER > TAMBAH RATING ]==========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void deleterelasi(List_R &Lr, List_P Lp, address_C AdrC){
    system("cls");
    string x;
    bool ada=false;
    address_P AdrP;
    address_R R=first(Lr);
    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
    cout << "  Masukan nama produk yang akan dihapus : ";cin >> x;
    AdrP=findproduct_P(Lp,x);
    if (AdrP!=NULL){
        while ((R!=NULL)&& (ada==false)){
            if ((product(R)==AdrP) and (customer(R)==AdrC)) {
                ada=true;
            } else {
                R=next(R);
            }
        }
        if (R==NULL){
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
            cout << "     Maaf data yang anda cari tidak ada" << endl;
            cout << "             Silahkan coba lagi";
            getch();
            system("cls");
        } else if (R==first(Lr)){
            deletefirst_R(Lr,R);
            deallocation_R(R);
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
            cout << "         Rating anda berhasil dihapus";
            getch();
            system("cls");
        } else if((next(R)==NULL)&& R!=first(Lr)) {
            deletelast_R(Lr,R);
            deallocation_R(R);
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
            cout << "         Rating anda berhasil dihapus";
            getch();
            system("cls");
        } else {
            deleteafter_R(Lr,R);
            deallocation_R(R);
            system("cls");
            cout << "================[ KING SHOP ]================" << endl;
            cout << "=                                           =" << endl;
            cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
            cout << "         Rating anda berhasil dihapus";
            getch();
            system("cls");
        }
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ USER > HAPUS RATING ]===========" << endl << endl;
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
        getch();
        system("cls");
    }
}

void viewratinghistory(List_R Lr, address_C AdrC){
    system("cls");
    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "===========[ USER > RIWAYAT RATING ]=========" << endl << endl;
    if(first(Lr) != NULL){
        viewrelation_RC(Lr, AdrC);
        getch();
        system("cls");
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "===========[ USER > RIWAYAT RATING ]=========" << endl << endl;
        cout << "     Maaf riwayat rating tidak ditemukan" << endl;
        getch();
    }

}

void updatecustomer(List_C &Lc, address_C &AdrC){
    infotype_C x;
    address_C SrcC;
    system("cls");

    cout << "================[ KING SHOP ]================" << endl;
    cout << "=                                           =" << endl;
    cout << "============[ USER > UPDATE INFO ]===========" << endl << endl;
    cout << "     Username      : "; cin >> x.uname;
    cout << "     Password      : "; cin >> x.pword;
    cout << "     Nama          : "; cin >> x.nama;
    cout << "     Jenis Kelamin : "; cin >> x.jk;
    cout << "     Tanggal Lahir : "; cin >> x.tgl;
    SrcC = findusername_C(Lc, x);
    if(SrcC == NULL){
        if(info(AdrC).uname != x.uname){
            if (AdrC == first(Lc)){
                deletefirst_C(Lc, AdrC);
                info(AdrC).uname = x.uname;
                info(AdrC).pword = x.pword;
                info(AdrC).nama = x.nama;
                info(AdrC).jk = x.jk;
                info(AdrC).tgl = x.tgl;
                insertcustomer_C(Lc, AdrC);
            } else if (AdrC == last(Lc)){
                deletelast_C(Lc, AdrC);
                info(AdrC).uname = x.uname;
                info(AdrC).pword = x.pword;
                info(AdrC).nama = x.nama;
                info(AdrC).jk = x.jk;
                info(AdrC).tgl = x.tgl;
                insertcustomer_C(Lc, AdrC);
            } else {
                deleteafter_C(Lc, AdrC);
                info(AdrC).uname = x.uname;
                info(AdrC).pword = x.pword;
                info(AdrC).nama = x.nama;
                info(AdrC).jk = x.jk;
                info(AdrC).tgl = x.tgl;
                insertcustomer_C(Lc, AdrC);
            }
        } else {
            info(AdrC).pword = x.pword;
            info(AdrC).nama = x.nama;
            info(AdrC).jk = x.jk;
            info(AdrC).tgl = x.tgl;
        }
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "============[ USER > UPDATE INFO ]===========" << endl << endl;
        cout << "     Selamat data anda berhasil diupdate";
        getch();
    } else {
        system("cls");
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "============[ USER > UPDATE INFO ]===========" << endl << endl;
        cout << "    Maaf username tersebut sudah terpakai" << endl;
        cout << "             Silahkan coba lagi";
        getch();
    }
    system("cls");
}

void viewtopten(List_P Lp){
    system("cls");
    infotype_P temp, elmten[999];
    int i,j,k,n;
    address_P P, Q;

    if(first(Lp) != NULL){
        P = first(Lp);
        i = 1;
        while(P != Q){
            elmten[i] = info(P);
            i++;
            P = next(P);
            Q = first(Lp);
        }
        j = 1;
        while(j <= i-1){
            k = 1;
            while(k <= i - j){
                if(elmten[k].avgprod < elmten[k+1].avgprod){
                    temp = elmten[k];
                    elmten[k] = elmten[k+1];
                    elmten[k+1] = temp;
                }
                k++;
            }
            j++;
        }
        n = 1;
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "=========[ GUEST > PRODUK NAIK DAUN ]========" << endl << endl;
        while(n <= i-1){
            cout << elmten[n].namaprod << endl;
            cout << elmten[n].harga << endl;
            cout << elmten[n].avgprod << endl << endl;
            n++;
        }
        getch();
        system("cls");
    } else {
        cout << "================[ KING SHOP ]================" << endl;
        cout << "=                                           =" << endl;
        cout << "=========[ GUEST > PRODUK NAIK DAUN ]========" << endl << endl;
        cout << "       Tidak ada produk yang naik daun";
        getch();
        system("cls");
    }
}
