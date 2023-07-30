#include<bits/stdc++.h>
using namespace std;


void cut(string rnaSequence){

    string start="AUG",stop1="UUA",stop2="UAG";
    int st=0,end=0;
    for(int i=0; i<rnaSequence.size(); i+=3){
        string str=rnaSequence.substr(i,3);
        if(str==start)st=i;
    }

}

// Function to transcribe DNA to RNA
string transcribeToRNA(const string& dnaSequence)
{
    string rnaSequence = dnaSequence;
    for (char& nucleotide : rnaSequence)
    {
        if (nucleotide == 'A')
        {
            nucleotide = 'T';
        }
        else if(nucleotide=='G')
        {
            nucleotide='C';
        }
        else if(nucleotide=='C')
        {
            nucleotide='G';
        }
        else if(nucleotide=='T')
        {
            nucleotide='A';
        }
    }
    return rnaSequence;
}

//Function to transcribe RNA to Protein sequence
string rnaToProtein(string rnaSequence){

    string protein=rnaSequence;
    for(char &ch:protein){
        if(ch=='T'){
            ch='U';
        }
    }

    //RETURN SEQUENCE FROM START CODON
    //st->HAVE LITTLE ISUUE
    string start="AUG";
    int st=0,n=protein.size();
    for(int i=0; i<n; i+=3){
        string str=protein.substr(i,3);
        if(start==str){
            st=i;
        }
    }

    string temp=protein.substr(st,n-st);
    return temp;
}

// Function to translate RNA to protein using the standard genetic code
string translateToProtein(const string& rnaSequence)
{
    unordered_map<string, char> geneticCode =
    {
        {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
        {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
        {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '_'}, {"UAG", '_'},
        {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '_'}, {"UGG", 'W'},
        {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
        {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
        {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
        {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
        {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
        {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
        {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'},
        {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
        {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
        {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
        {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
        {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
    };

    string proteinSequence;
    for (size_t i = 0; i < rnaSequence.length(); i += 3)
    {
        string codon = rnaSequence.substr(i, 3);
        if (geneticCode.find(codon) != geneticCode.end())
        {
            char aminoAcid = geneticCode[codon];
            if (aminoAcid == '_')   // Stop codon encountered
            {
                proteinSequence+='_';
                break;
            }
            proteinSequence += aminoAcid;
        }
    }
    return proteinSequence;
}

int main()
{

    string dnaSequence, rnaSequence, protein;

    // Input DNA sequence from the user
    cout << "Enter DNA sequence: ";
    cin >> dnaSequence;

    // Transcribe DNA to RNA
    rnaSequence = transcribeToRNA(dnaSequence);
    cout << "RNA sequence: " << rnaSequence <<"-->";

    string proteinSequence=rnaToProtein(rnaSequence);
    cout<<proteinSequence<<endl;
    // Translate RNA to protein
    protein = translateToProtein(proteinSequence);
    cout << "Protein: " << protein << std::endl;

    return 0;
}
