//Write your code in this file
#include <stdio.h>
#include <ctype.h> //för versalerna

//struct för att det är det smidigaste sättet att spara samlad data. 
struct Elev
{
    char namn[10]; //max 10 tecken i namnet
    int prov[13]; //antal prov
};

int main()
{
    //Spara ner alla elev-structs i en array så att jag kan gå igenom dom. 
    struct Elev elever[5]; //array med de 5 eleverna. 

    float elevernasMedelvärden[5];
    //för varje elev: ta in namnet och alla provresultat
    for (int i = 0; i < 5; i++)
    {
        printf("Ange namn och 13 provresultat för elev %d:\n", i+1);
        scanf("%s", elever[i].namn);
        elever[i].namn[0] = toupper(elever[i].namn[0]); //versaler på första bokstaven
       
        for (int j = 0; j < 13; j++)
        {
            scanf("%d", &elever[i].prov[j]);
        }
        
    }


// räkna ut varje elevs medelpoäng och hitta högsta
    float högstaMedel = -1.0;
    int indexHögstaMedelElev = -1;
    float totalMedel = 0.0;

for (int i = 0; i < 5; i++)
{
    int summa = 0;
    for (int j = 0; j < 13; j++)
    {
        summa += elever[i].prov[j];
    }

    float medel = summa / 13.0; 
    elevernasMedelvärden[i] = medel;
    totalMedel += medel;

    if (medel > högstaMedel){
        högstaMedel = medel;
        indexHögstaMedelElev = i;
    }
}

printf("Högsta medel: %s", elever[indexHögstaMedelElev].namn);

totalMedel = totalMedel / 5.0;
int hittadeEleverUnderMedel = 0;

for (int i = 0; i < 5; i++){
    if(elevernasMedelvärden[i] < totalMedel){
        printf("%s\n", elever[i].namn);
        hittadeEleverUnderMedel = 1;
    }
}
    return 0;
}
