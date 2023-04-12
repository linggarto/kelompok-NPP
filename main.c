#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bank {
    char nama[50];
    char alamat[100];
    int saldo;
    struct Bank* next;
} Bank;

Bank* head = NULL;

// Fungsi untuk menambah data
void create() {
    Bank* baru = (Bank*) malloc(sizeof(Bank));
    printf("Masukkan Nama: ");
    scanf("%s", baru->nama);
    printf("Masukkan Alamat: ");
    scanf("%s", baru->alamat);
    printf("Masukkan Saldo: ");
    scanf("%d", &baru->saldo);
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
    } else {
        Bank* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = baru;
    }
}

// Fungsi untuk mencari data
void search() {
    char nama[50];
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            printf("Nama: %s\n", ptr->nama);
            printf("Alamat: %s\n", ptr->alamat);
            printf("Saldo: %d\n", ptr->saldo);
            return;
        }
        ptr = ptr->next;
    }
    printf("Data tidak ditemukan\n");
}

// Fungsi untuk mengupdate data
void update() {
    char nama[50];
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            printf("Masukkan Alamat Baru: ");
            scanf("%s", ptr->alamat);
            printf("Masukkan Saldo Baru: ");
            scanf("%d", &ptr->saldo);
            printf("Data berhasil diupdate\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Data tidak ditemukan\n");
}

// Fungsi untuk menghapus data
void delete() {
    char nama[50];
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    Bank* ptr = head;
    Bank* prev = NULL;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("Data berhasil dihapus\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Data tidak ditemukan\n");
}

// Fungsi untuk menampilkan semua data
void display() {
    Bank* ptr = head;
    while (ptr != NULL) {
        printf("Nama: %s\n", ptr->nama);
        printf("Alamat: %s\n", ptr->alamat);
        printf("Saldo: %d\n", ptr->saldo);
        ptr = ptr->next;
    }
}

// Fungsi untuk menyimpan data ke dalam file
void save() {
    FILE* file = fopen("data_bank.txt", "w");
    Bank* ptr = head;
    while (ptr != NULL) {
        fprintf(file, "%s %s %d\n", ptr->nama, ptr->alamat, ptr->saldo);
    	ptr = ptr->next;
	}
	fclose(file);
	printf("Data berhasil disimpan ke dalam file\n");
}

// Fungsi untuk membaca data dari file
void load() {
	FILE* file = fopen("data_bank.txt", "r");
	if (file == NULL) {
		printf("File tidak ditemukan\n");
		return;
	}
	char nama[50], alamat[100];
	int saldo;
	while (fscanf(file, "%s %s %d", nama, alamat, &saldo) == 3) {
		Bank* baru = (Bank*) malloc(sizeof(Bank));
		strcpy(baru->nama, nama);
		strcpy(baru->alamat, alamat);
		baru->saldo = saldo;
		baru->next = NULL;
		if (head == NULL) {
			head = baru;
		} else {
			Bank* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = baru;
		}
	}
	fclose(file);
	printf("Data berhasil dibaca dari file\n");
}

// Fungsi untuk login
int login() {
	char username[50], password[50];
	printf("Masukkan Username: ");
	scanf("%s", username);
	printf("Masukkan Password: ");
	scanf("%s", password);
	if (strcmp(username, "admin") == 0 && strcmp(password, "ganteng") == 0) {
		printf("Login Berhasil\n");
		return 1;
	} else {
		printf("Username atau Password salah\n");
		return 0;
	}
}

int main() {
	if (!login()) {
		return 0;
	}
	int pilihan;
	while (1) {
		printf("Menu:\n");
		printf("1. Tambah Data\n");
		printf("2. Cari Data\n");
		printf("3. Update Data\n");
		printf("4. Hapus Data\n");
		printf("5. Tampilkan Data\n");
		printf("6. Simpan ke File\n");
		printf("7. Baca dari File\n");
		printf("8. Keluar\n");
		printf("Pilih: ");
		scanf("%d", &pilihan);
		switch (pilihan) {
			case 1:
				create();
				break;
			case 2:
				search();
				break;
			case 3:
				update();
				break;
			case 4:
				delete();
				break;
			case 5:
				display();
				break;
			case 6:
				save();
				break;
			case 7:
				load();
				break;
			case 8:
				return 0;
			default:
				printf("Pilihan tidak tersedia\n");
		}
		printf("\n");
	}
	return 0;
}
