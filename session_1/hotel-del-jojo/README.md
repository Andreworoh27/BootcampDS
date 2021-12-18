main.cpp:
  -main:
    membuat list untuk 3 data pertama yang akan di baca melalui file dan juga memanggil function import dan menu
  -import_data_from_file:
    digunakan untuk mengambil data dari file customer_data.txt dengan menggunakan file processing dan juga menyimpannya dalam bentuk linked list
    tetapi sebelum file ini dipannggil pertama linked list sudah dibuat terlebih dahulu pada function main
    setelah data berhasil di simpan ke dalam list maka akan ditampilkan seluruh data
  -menu :
    berisi opsi untuk melakukan operasi yang nanti operasinya akan menggunakan function dari customer.h
    
customer.h
  -create:
   untuk membuat node baru pada linked list dengan menggunakan malloc dan mengisi data yang baru sesuai input user dan melakukan validasi untuk
   umur agak tidak boleh negatif dan juga tidak melebihi 100 dan juga validasi pada bagian input kamar agak sesuai dengan format yang telah ditentukan
   dan data kamar akan di sinkronasi dengan data yang ada di room.txt
  -read :
    menampilkan seluruh list yang ada dalam bentuk tabel
  -update :
    mengubah data yang sekarang ada di linked list dengan cara mengambil alamat target yang akan di ubah dan juga melakukan validasi 
    untuk input kamar agar sesuai dengan format yang ditentukan
    sesudah function ini di jalankan maka akan dilanjankan juga function untuk mengupdate seluruh data di customer.txt dengan cara mengkonfirmasi
    dengan huruf y pada input yang akan di minta nanti
   -delete:
    menghapus data dari linked list yang di targetkan dengan cara mengambil 1 alamat di belakang target yang di tentukan dan mengubah pointer pada alamat
    tsb agar menunjuk kepada list yang berikutnya dan linked list yang akan di hapus akan dihapus dengan function free()
