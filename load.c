//
// Demo for reading and writing a text file
//
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_LEN  128
#define RECORD_FILE "books.dat"

//Store a book record to the persistent file
static int store(const char* filename){
	FILE *fp;
	char *booktitle="XJCO PROGRAMMING Project";
	//Number of books
	int nbook = 1;
	fp = fopen(filename, "w+");
	if (!fp) {
		fprintf(stderr, "Failed in opening %s\n", filename);
		return -1;
	}

	fprintf(fp, "%d\n", nbook);
	
	//Book ID:
	fprintf(fp, "ID:%d\n", 1);
	//Book Title:
	fprintf(fp, "Book Title:%s\n", booktitle);
	fclose(fp);

	return 0;
}


//Load from the book record file
static int load(const char* filename){
	FILE *fp;
	char buf[BUF_LEN];
	int nbook = 0;
	int bookid;
	int title[BUF_LEN];
        int i;
 	fp = fopen(filename, "r");
	if (!fp){
		fprintf(stderr, "Error in opening books.dat\n");
		return -1;
	}
	
        //Read the first line
        if (fgets(buf, BUF_LEN, fp) != NULL){
        	sscanf(buf, "%d\n", &nbook);
            	printf("The number of book entries is: %d\n", nbook);
        }
	else{
		fprintf(stderr, "Error in reading: books.dat\n");
		return -1; 
	}

        //Read in book entries
        i = 0;
        while(i<nbook){
                //Load book id
		fgets(buf, BUF_LEN, fp);
		printf("Read in: %s", buf);
		sscanf(buf,"ID:%d\n", &bookid);
		//Load book title
		fgets(buf, BUF_LEN, fp);
		printf("Read in: %s", buf);
		//Here, I don't use %s to read in the book title, as sscanf will stop when meeting a whitespace
		//Intead, I use %[^\n] because it allows me to read to the end of the line
		sscanf(buf, "Book Title:\%[^\n]", title);
		//Print out the content
                printf("I have loaded in: ID: %d, Title: %s\n", bookid, title);
        	i++;
        }
	fclose(fp);
	return 0;
}


int main(){
	int ret;
	ret = store(RECORD_FILE);
	
	if (ret != 0)
		return ret;


	ret = load(RECORD_FILE);

	return ret;
		
}
