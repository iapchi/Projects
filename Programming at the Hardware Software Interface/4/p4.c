/*
Jacky Li

*/
//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Naming data types
typedef struct node{
    int lineno;
    struct node *next;
}node;
//Main function
int main(int argc, char *argv[])
{
	//If more than 4 inputs, print out correct usage
    if (argc != 4){
        printf("Usage: %s <flag> <inputfile> <outputfile>\n", argv[0]);
        return 0;
    }
	//If theres no flags and or other flags, print out only l,c,b flags
    if (strcmp(argv[1],"-l") != 0 && strcmp(argv[1],"-c") != 0 && strcmp(argv[1],"-b") != 0){
        printf("Usage: %s '-l' | '-c' | '-b'  %s %s\n", argv[0], argv[2], argv[3]);
        return 0;
    }
	//reading file defined
    FILE *inp = fopen(argv[2],"r");
    if (inp == NULL){
        printf("Could not open file %s\n", argv[2]);
        return 0;
    }
	//writing file defined
    FILE *out = fopen(argv[3],"w");
    if (inp == NULL){
        printf("Could not open file %s\n", argv[3]);
        return 0;
    }
	//pointers
    char **labels = (char **)malloc(sizeof(char *));
    int *definition = (int *)malloc(sizeof(int));
	//defined data
    int labelsize = 1;
    int labelind = 0;
//functions for each flag when they are == 0  or != 0
    if (strcmp(argv[1],"-c") != 0){
		//declarations of variable names
        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            if (isnotwhite){
                fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ' && line[i] != '\r' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }
                    if (i < ind && line[i] == ':'){
                        labels[labelind] = (char *)malloc(sizeof(char) * (i + 1) );
                        strncpy(labels[labelind],line,i);
                        labels[labelind][i] = '\0';
                        definition[labelind] = lineno-1;
                        labelind++;
                        if (labelind == labelsize){
                            labels = (char **)realloc(labels,sizeof(char *) * 2 * labelsize);
                            definition = (int *)realloc(definition,sizeof(int) * 2 * labelsize);
                            labelsize *= 2;
                        }

                    }


                }
            }
            else {
                fprintf(out,"%s",line);
            }
            if (ch == EOF){
                break;
            }

        }

	}
    //fclose(out);
    if (strcmp(argv[1],"-c") == 0&&(strcmp(argv[1],"-l") != 0)){
		//declarations of variable names
        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            if (isnotwhite){
                //fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ' && line[i] != '\r' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }
                    if (i < ind && line[i] == ':'){
                        labels[labelind] = (char *)malloc(sizeof(char) * (i + 1) );
                        strncpy(labels[labelind],line,i);
                        labels[labelind][i] = '\0';
                        definition[labelind] = lineno-1;
                        labelind++;
                        if (labelind == labelsize){
                            labels = (char **)realloc(labels,sizeof(char *) * 2 * labelsize);
                            definition = (int *)realloc(definition,sizeof(int) * 2 * labelsize);
                            labelsize *= 2;
                        }

                    }


                }
            }
            else {
                //fprintf(out,"%s",line);
            }
            if (ch == EOF){
                break;
            }

        }

    }
    //fclose(out);

    if (strcmp(argv[1],"-c") != 0&&(strcmp(argv[1],"-b") == 0&&(strcmp(argv[1],"-l") != 0))){
		//declarations of variable names
        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            if (isnotwhite){
                fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ' && line[i] != '\r' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }
                    if (i < ind && line[i] == ':'){
                        labels[labelind] = (char *)malloc(sizeof(char) * (i + 1) );
                        strncpy(labels[labelind],line,i);
                        labels[labelind][i] = '\0';
                        definition[labelind] = lineno-1;
                        labelind++;
                        if (labelind == labelsize){
                            labels = (char **)realloc(labels,sizeof(char *) * 2 * labelsize);
                            definition = (int *)realloc(definition,sizeof(int) * 2 * labelsize);
                            labelsize *= 2;
                        }

                    }


                }
            }
            else {
                fprintf(out,"%s",line);
            }
            if (ch == EOF){
                break;
            }

        }

    }
    //fclose(out);
	
/*   if (strcmp(argv[1],"-c") == 0&&(strcmp(argv[1],"-l") != 0)){
		//variable declaration
        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            if (isnotwhite){
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ' && line[i] != '\r' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }
                    if (i < ind && line[i] == ':'){
                        labels[labelind] = (char *)malloc(sizeof(char) * (i + 1) );
                        strncpy(labels[labelind],line,i);
                        labels[labelind][i] = '\0';
                        definition[labelind] = lineno-1;
                        labelind++;
                        if (labelind == labelsize){
                            labels = (char **)realloc(labels,sizeof(char *) * 2 * labelsize);
                            definition = (int *)realloc(definition,sizeof(int) * 2 * labelsize);
                            labelsize *= 2;
                        }

                    }


                }
            }
            else if
                (ch == EOF){
                break;
            }

        }
        fprintf(out,"Cross Reference Table\n");
        fprintf(out,"\n\tIdentifier\tDefinition\tUse\n\n");
        node **labelnodes = (node **)malloc(sizeof(node *) * labelind);
    int k;
    for (k=0;k<labelind;k++){
        labelnodes[k] = NULL;
    }
        fseek(inp, 0, SEEK_SET);

        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            //printf("line %d\n",lineno);
            if (isnotwhite){
                //fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }

                    if (i < ind && line[i] == ':'){
                        i = i + 1;
                    }
                    else {
                        i = 0;
                    }
                    if (i == ind)
                        continue;
                    while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;

                    while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;
                    while (i < ind && line[i] != '#'){
                        while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r'))
                            i++;
                        if (i < ind && (line[i] == '$' || line[i] == '\'' || line[i] == '"')){
                            if (line[i] == '$'){
                                while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r')){
                                    i++;
                                }
                            }
                            else if (line[i] == '\''){
                                i++;
                                while (i < ind && !(line[i] == '\'')){
                                    i++;
                                }
                            }
                            else if (line[i] == '"'){
                                i++;
                                while (i < ind && !(line[i] == '"')){
                                    i++;
                                }
                            }
                        }
                        else if (i < ind && line[i] == '#')
                            continue;
                        else if (i < ind && line[i] == ','){
                            i++;
                        }
                        else {
                            int start = i;
                            while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r' || line[i] == '\n') ){
                                i++;
                            }
                            ///
                            int j = 0;
                            for (j=0;j<labelind;j++){
                                if (i != start && strncmp(labels[j],line+start,i-start) == 0){
                                    node *n = (node *)malloc(sizeof(node));
                                    n->lineno = lineno-1;
                                    n->next = NULL;
                                    if (labelnodes[j] == NULL){
                                        labelnodes[j] = n;
                                    }
                                    else {
                                        node *t = labelnodes[j];
                                        while(t != NULL && t->next != NULL){
                                            t = t->next;
                                        }
                                        if (t->lineno != n->lineno)
                                            t->next = n;
                                    }
                                    break;
                                }
                            }

                        }
                    }

                }
            }
            //printf("line:%d\n",lineno);
            if (ch == EOF){
                break;
            }

        }



        int i;
        for (i=0;i<labelind;i++){
            fprintf(out,"\t%-10s\t%-10d\t",labels[i],definition[i]);
            node *n = labelnodes[i];
            while (n != NULL){
                fprintf(out,"middpart%d ",n->lineno);
                n = n->next;
            }
            fprintf(out,"\n");
        }

    }
*/
    if (strcmp(argv[1],"-c") == 0&&(strcmp(argv[1],"-b") != 0&&(strcmp(argv[1],"-l") != 0))){
		fprintf(out,"Cross Reference Table\n");
        fprintf(out,"\n\tIdentifier\tDefinition\tUse\n\n");


        node **labelnodes = (node **)malloc(sizeof(node *) * labelind);
    int k;
    for (k=0;k<labelind;k++){
        labelnodes[k] = NULL;
    }


        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        //set file pointer to start

        fseek(inp, 0, SEEK_SET);

        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            //printf("line %d\n",lineno);
            if (isnotwhite){
                //fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }

                    if (i < ind && line[i] == ':'){
                        i = i + 1;
                    }
                    else {
                        i = 0;
                    }
                    if (i == ind)
                        continue;
                    while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;

                    while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;
                    while (i < ind && line[i] != '#'){
                        while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r'))
                            i++;
                        if (i < ind && (line[i] == '$' || line[i] == '\'' || line[i] == '"')){
                            if (line[i] == '$'){
                                while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r')){
                                    i++;
                                }
                            }
                            else if (line[i] == '\''){
                                i++;
                                while (i < ind && !(line[i] == '\'')){
                                    i++;
                                }
                            }
                            else if (line[i] == '"'){
                                i++;
                                while (i < ind && !(line[i] == '"')){
                                    i++;
                                }
                            }
                        }
                        else if (i < ind && line[i] == '#')
                            continue;
                        else if (i < ind && line[i] == ','){
                            i++;
                        }
                        else {
                            int start = i;
                            while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r' || line[i] == '\n') ){
                                i++;
                            }
                            ///
                            int j = 0;
                            for (j=0;j<labelind;j++){
                                if (i != start && strncmp(labels[j],line+start,i-start) == 0){
                                    node *n = (node *)malloc(sizeof(node));
                                    n->lineno = lineno-1;
                                    n->next = NULL;
                                    if (labelnodes[j] == NULL){
                                        labelnodes[j] = n;
                                    }
                                    else {
                                        node *t = labelnodes[j];
                                        while(t != NULL && t->next != NULL){
                                            t = t->next;
                                        }
                                        if (t->lineno != n->lineno)
                                            t->next = n;
                                    }
                                    break;
                                }
                            }

                        }
                    }

                }
            }
            //printf("line:%d\n",lineno);
            if (ch == EOF){
                break;
            }

        }



        int i;
        for (i=0;i<labelind;i++){
            fprintf(out,"\t%-10s\t%-10d\t",labels[i],definition[i]);
            node *n = labelnodes[i];
            while (n != NULL){
                fprintf(out,"%d ",n->lineno);
                n = n->next;
            }
            fprintf(out,"\n");
        }

	}

    if (strcmp(argv[1],"-b") == 0&&(strcmp(argv[1],"-l") != 0)){
		fprintf(out,"\n\n");
		fprintf(out,"Cross Reference Table\n");
        fprintf(out,"\n\tIdentifier\tDefinition\tUse\n\n");


        node **labelnodes = (node **)malloc(sizeof(node *) * labelind);
    int k;
    for (k=0;k<labelind;k++){
        labelnodes[k] = NULL;
    }


        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        //set file pointer to start

        fseek(inp, 0, SEEK_SET);

        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            //printf("line %d\n",lineno);
            if (isnotwhite){
                //fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }

                    if (i < ind && line[i] == ':'){
                        i = i + 1;
                    }
                    else {
                        i = 0;
                    }
                    if (i == ind)
                        continue;
                    while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;

                    while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;
                    while (i < ind && line[i] != '#'){
                        while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r'))
                            i++;
                        if (i < ind && (line[i] == '$' || line[i] == '\'' || line[i] == '"')){
                            if (line[i] == '$'){
                                while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r')){
                                    i++;
                                }
                            }
                            else if (line[i] == '\''){
                                i++;
                                while (i < ind && !(line[i] == '\'')){
                                    i++;
                                }
                            }
                            else if (line[i] == '"'){
                                i++;
                                while (i < ind && !(line[i] == '"')){
                                    i++;
                                }
                            }
                        }
                        else if (i < ind && line[i] == '#')
                            continue;
                        else if (i < ind && line[i] == ','){
                            i++;
                        }
                        else {
                            int start = i;
                            while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r' || line[i] == '\n') ){
                                i++;
                            }
                            ///
                            int j = 0;
                            for (j=0;j<labelind;j++){
                                if (i != start && strncmp(labels[j],line+start,i-start) == 0){
                                    node *n = (node *)malloc(sizeof(node));
                                    n->lineno = lineno-1;
                                    n->next = NULL;
                                    if (labelnodes[j] == NULL){
                                        labelnodes[j] = n;
                                    }
                                    else {
                                        node *t = labelnodes[j];
                                        while(t != NULL && t->next != NULL){
                                            t = t->next;
                                        }
                                        if (t->lineno != n->lineno)
                                            t->next = n;
                                    }
                                    break;
                                }
                            }

                        }
                    }

                }
            }
            //printf("line:%d\n",lineno);
            if (ch == EOF){
                break;
            }

        }



        int i;
        for (i=0;i<labelind;i++){
            fprintf(out,"\t%-10s\t%-10d\t",labels[i],definition[i]);
            node *n = labelnodes[i];
            while (n != NULL){
                fprintf(out,"%d ",n->lineno);
                n = n->next;
            }
            fprintf(out,"\n");
        }

	}

/*  //reading .mal file cores
        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            if (isnotwhite){
                fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != ' ' && line[i] != '\r' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }
                    if (i < ind && line[i] == ':'){
                        labels[labelind] = (char *)malloc(sizeof(char) * (i + 1) );
                        strncpy(labels[labelind],line,i);
                        labels[labelind][i] = '\0';
                        definition[labelind] = lineno-1;
                        labelind++;
                        if (labelind == labelsize){
                            labels = (char **)realloc(labels,sizeof(char *) * 2 * labelsize);
                            definition = (int *)realloc(definition,sizeof(int) * 2 * labelsize);
                            labelsize *= 2;
                        }

                    }


                }
            }
            else {
                fprintf(out,"%s",line);
            }
            if (ch == EOF){
                break;
            }

        }

    }
	//Reading and print CRT core.
        fprintf(out,"Cross Reference Table\n");
        fprintf(out,"\n\tIdentifier\tDefinition\tUse\n\n");


        node **labelnodes = (node **)malloc(sizeof(node *) * labelind);
    int k;
    for (k=0;k<labelind;k++){
        labelnodes[k] = NULL;
    }


        int lineno = 1;
        char line[81];
        int ind = 0;
        char ch;
        //set file pointer to start

        fseek(inp, 0, SEEK_SET);

        while (1){
            ch = fgetc(inp);
            int isnotwhite = 0;
            ind = 0;
            while (EOF != ch && ch != '\n'){
                if (ch != '\t' && ch != ' ' && ch != '\r'){
                    isnotwhite = 1;
                }
                line[ind] = ch;
                ind++;
                ch = fgetc(inp);
            }
            if (ch == '\n'){
                line[ind] = ch;
                ind++;
            }
            line[ind] = '\0';
            //printf("line %d\n",lineno);
            if (isnotwhite){
                //fprintf(out,"%d\t%s",lineno,line);
                lineno++;
                if (line[0] != '#'){
                    int i = 0;
                    while (i < ind){
                        if (line[i] != '\t' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ' && line[i] != ':'){
                            i++;
                        }
                        else {
                            break;
                        }
                    }

                    if (i < ind && line[i] == ':'){
                        i = i + 1;
                    }
                    else {
                        i = 0;
                    }
                    if (i == ind)
                        continue;
                    while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;

                    while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == '\r'))
                        i++;
                    while (i < ind && line[i] != '#'){
                        while (i < ind && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r'))
                            i++;
                        if (i < ind && (line[i] == '$' || line[i] == '\'' || line[i] == '"')){
                            if (line[i] == '$'){
                                while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r')){
                                    i++;
                                }
                            }
                            else if (line[i] == '\''){
                                i++;
                                while (i < ind && !(line[i] == '\'')){
                                    i++;
                                }
                            }
                            else if (line[i] == '"'){
                                i++;
                                while (i < ind && !(line[i] == '"')){
                                    i++;
                                }
                            }
                        }
                        else if (i < ind && line[i] == '#')
                            continue;
                        else if (i < ind && line[i] == ','){
                            i++;
                        }
                        else {
                            int start = i;
                            while (i < ind && !(line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\r' || line[i] == '\n') ){
                                i++;
                            }
                            ///
                            int j = 0;
                            for (j=0;j<labelind;j++){
                                if (i != start && strncmp(labels[j],line+start,i-start) == 0){
                                    node *n = (node *)malloc(sizeof(node));
                                    n->lineno = lineno-1;
                                    n->next = NULL;
                                    if (labelnodes[j] == NULL){
                                        labelnodes[j] = n;
                                    }
                                    else {
                                        node *t = labelnodes[j];
                                        while(t != NULL && t->next != NULL){
                                            t = t->next;
                                        }
                                        if (t->lineno != n->lineno)
                                            t->next = n;
                                    }
                                    break;
                                }
                            }

                        }
                    }

                }
            }
            //printf("line:%d\n",lineno);
            if (ch == EOF){
                break;
            }

        }



        int i;
        for (i=0;i<labelind;i++){
            fprintf(out,"\t%-10s\t%-10d\t",labels[i],definition[i]);
            node *n = labelnodes[i];
            while (n != NULL){
                fprintf(out,"%d ",n->lineno);
                n = n->next;
            }
            fprintf(out,"\n");
        }

    }*/

    return 0;
}
