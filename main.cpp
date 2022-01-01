
// Created by bouricha on 2021-12-31.
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <map>
using namespace std ;
#include <cstdlib>
#define nbr_sommet 9
// Pour trouver la distance minimale
int Trouver_DIST_Min(vector<int>dist, map<int,bool> passer)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int i = 0; i < nbr_sommet; i++)
        // s'il na pas passer donc c'est false
        if (!passer.find(i)->second && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}
void printSolution(vector<int>dist ,int src )
{
    cout <<"Sommet   Distance a partir de de " << src << "\n" ;
    for (int i = 0; i < nbr_sommet; i++)
        cout << " \n"<< i<< " \t\t"<<dist[i];
}
vector<int> dijkstra(int graph[nbr_sommet][nbr_sommet] ,int debut)
{
    vector<int>dist ;
    map<int,bool> passer;

    // initialiser le vect et la map
    for(int i=0;i < nbr_sommet;i++)
    {

        // n initialise tous le vecteur avec des INT c'est une grande valeur
        // pou map de verificationnc'est par de false
       // dist[i]=INT_MAX;
        dist.insert(dist.begin()+i,INT_MAX);
        passer.insert(make_pair(i,false));
        //Initialiser la distance de la source par 0
    }
    // rendre la premiere cse a 0
    //dist[debut]=0;
    dist.insert(dist.begin(),0);
    for(int j=0; j < nbr_sommet-1;j++)
    {
        int sommet = Trouver_DIST_Min(dist ,passer) ;
        // donc ce sommet est deja passer
        passer.find(sommet)->second=true ;
        for (int i=0 ;i<nbr_sommet;i++){
            // verifier qui n'est passer dans la map
            // si graph[sommet][i]!=0 donc il y un poit entre ces sommet donc c'est voisin
            //verifier que la distance n'est pas l'infini ou bien la grand valeur
            if(!passer.find(i)->second && graph[sommet][i] &&  *dist.begin()!=INT_MAX
               && (dist.at(sommet)-1)+(graph[sommet][i]) < dist[i] ) {



                dist[i]=dist.at(sommet)+graph[sommet][i];

            }
        }



    }

    return dist ;



}
int main()
{
  

    vector<int> d ;
    // Let us create the example graph discussed above
    int graph[nbr_sommet][nbr_sommet] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                          { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                          { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                          { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                          { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                          { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                          { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                          { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                          { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    d= dijkstra(graph, 0);


    printSolution(d,0);


    return 0;
}
