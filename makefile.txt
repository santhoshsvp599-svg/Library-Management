out:main.o stud_add.o stud_del.o stud_sort.o stud_save.o stud_exit.o stud_show.o stud_mod.o	
	gcc main.o stud_add.o stud_del.o stud_sort.o stud_save.o stud_exit.o stud_show.o stud_mod.o -o out

main.o:main.c header.h
	gcc -c main.c
stud_add.o:stud_add.c header.h
	gcc -c stud_add.c
stud_del.o:stud_del.c header.h
	gcc -c stud_del.c

stud_sort.o:stud_sort.c header.h
	gcc -c stud_sort.c

stud_save.o:stud_save.c header.h
	gcc -c stud_save.c

stud_exit.o:stud_exit.c header.h
	gcc -c stud_exit.c

stud_show.o:stud_show.c header.h
	gcc -c stud_show.c

stud_mod.o:stud_mod.c header.h
	gcc -c stud_mod.c