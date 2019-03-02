#include "Node.cpp"
#include "SinglyLinkedList.cpp"
#include "CityNode.cpp"
#include "MinHeap.cpp"

#include<iostream>
using namespace std;

// City Nodes

CityNode Arad       (1, " Arad"          ,366,0);
CityNode Timisoara  (2, " Timisoara"     ,329,118);
CityNode Sibiu      (3, " Sibiu"         ,253,140,151);
CityNode Zerind     (4, " Zerind"        ,374,75);
CityNode Lugoj      (5, " Lugoj"         ,244,111);
CityNode Rimincu    (6, " Rimincu-Vlicea",193,80);
CityNode Fagaras    (7, " Fagaras"       ,178,99);
CityNode Oradea     (8, " Oradea"        ,380,71,151);
CityNode Mehadia    (9, " Mehadia"       ,241,70);
CityNode Craiova    (10," Craiova"       ,160,146,120);
CityNode Doberta    (11," Doberta"       ,242,75);
CityNode Pitesti    (12," Pitesti"       ,98 ,97,138);
CityNode Bucharest  (13," Bucharest"     ,0  ,211,101);

class RomaniaMap
{
    public:

        int V;
        SinglyLinkedList<int> *ConnectedCities;

    public:

        RomaniaMap(int V)
        {
            this->V=V;
            ConnectedCities=new SinglyLinkedList<int>[V];
        }
        void AddCity(int X,int Y)
        {
            ConnectedCities[X].InsertAtEnd(Y);
        }
        void BreadthFirstSearch(int CurrentCity,int End)
        {
            bool *Visited=new bool[V];
            for(int i=0;i<V;i++)
            {
                Visited[i]=false;
            }
            SinglyLinkedList<int> Queue;
            Visited[CurrentCity]=true;
            Queue.InsertAtEnd(CurrentCity);
            int Cost=0;
            string Result="\0";
            while(Queue.GetSize()>0)
            {
                CurrentCity=Queue.GetNth(1);
                if(CurrentCity==Arad.CityID)
                {
                    Cost+=Arad.PathCost1;
                    Result+=Arad.CityName+"\n";
                }
                else if(CurrentCity==Timisoara.CityID)
                {
                    Cost+=Timisoara.PathCost1;
                    Result+=Timisoara.CityName+"\n";
                }
                else if(CurrentCity==Sibiu.CityID)
                {
                    if(Result.find("Oradea")>-1)
                    {
                        Cost+=Sibiu.PathCost2;
                    }
                    else
                    {
                        Cost+=Sibiu.PathCost1;
                    }
                    Result+=Sibiu.CityName+"\n";
                }
                else if(CurrentCity==Zerind.CityID)
                {
                    Cost+=Zerind.PathCost1;
                    Result+=Zerind.CityName+"\n";
                }
                else if(CurrentCity==Lugoj.CityID)
                {
                    Cost+=Lugoj.PathCost1;
                    Result+=Lugoj.CityName+"\n";
                }
                else if(CurrentCity==Rimincu.CityID)
                {
                    Cost+=Rimincu.PathCost1;
                    Result+=Rimincu.CityName+"\n";
                }
                else if(CurrentCity==Fagaras.CityID)
                {
                    Cost+=Fagaras.PathCost1;
                    Result+=Fagaras.CityName+"\n";
                }
                else if(CurrentCity==Oradea.CityID)
                {
                    if(Result.find("Sibiu")>-1)
                    {
                        Cost+=Oradea.PathCost1;
                    }
                    else
                    {
                        Cost+=Oradea.PathCost2;
                    }
                    Result+=Oradea.CityName+"\n";
                }
                else if(CurrentCity==Mehadia.CityID)
                {
                    Cost+=Mehadia.PathCost1;
                    Result+=Mehadia.CityName+"\n";
                }
                else if(CurrentCity==Craiova.CityID)
                {
                    if(Result.find("Rimincu")>-1)
                    {
                        Cost+=Craiova.PathCost1;
                    }
                    else
                    {
                        Cost+=Craiova.PathCost2;
                    }
                    Result+=Craiova.CityName+"\n";
                }
                else if(CurrentCity==Doberta.CityID)
                {
                    Result+=Doberta.CityName+"\n";
                    Cost+=Doberta.PathCost1;
                }
                else if(CurrentCity==Pitesti.CityID)
                {
                    if(Result.find("Rimincu")>-1)
                    {
                        Cost+=Pitesti.PathCost1;
                    }
                    else
                    {
                        Cost+=Pitesti.PathCost2;
                    }
                    Result+=Pitesti.CityName+"\n";
                }
                else if(CurrentCity==End)
                {
                    if(Result.find("Fagaras")>-1)
                    {
                        Cost+=Bucharest.PathCost1;
                    }
                    else
                    {
                        Cost+=Bucharest.PathCost2;
                    }
                    Result+=Bucharest.CityName+"\n";
                    cout<<Result;
                    cout<<"\n Path Cost : "<<Cost<<endl;
                    break;
                }
                Node<int> *Temp=ConnectedCities[CurrentCity].GetHead();
                while(Temp!=0)
                {
                    if(Visited[Temp->GetData()] == false)
                    {
                        Visited[Temp->GetData()]=true;
                        Queue.InsertAtEnd(Temp->GetData());
                    }
                    Temp=Temp->GetNext();
                }
                Queue.DeleteAtFirst();
            }
        }
        void DFSUtil(int CurrentCity, bool Visited[],int Cost,string Result)
        {
            Visited[CurrentCity]=true;
            if(CurrentCity==Arad.CityID)
            {
                Cost+=Arad.PathCost1;
                Result+=Arad.CityName+"\n";
            }
            else if(CurrentCity==Timisoara.CityID)
            {
                Cost+=Timisoara.PathCost1;
                Result+=Timisoara.CityName+"\n";
            }
            else if(CurrentCity==Sibiu.CityID)
            {
                Cost+=Sibiu.PathCost1;
                Result+=Sibiu.CityName+"\n";
            }
            else if(CurrentCity==Zerind.CityID)
            {
                Cost+=Zerind.PathCost1;
                Result+=Zerind.CityName+"\n";
            }
            else if(CurrentCity==Lugoj.CityID)
            {
                Cost+=Lugoj.PathCost1;
                Result+=Lugoj.CityName+"\n";
            }
            else if(CurrentCity==Rimincu.CityID)
            {
                Cost+=Rimincu.PathCost1;
                Result+=Rimincu.CityName+"\n";
            }
            else if(CurrentCity==Fagaras.CityID)
            {
                Cost+=Fagaras.PathCost1;
                Result+=Fagaras.CityName+"\n";
            }
            else if(CurrentCity==Oradea.CityID)
            {
                Cost+=Oradea.PathCost1;
                Result+=Oradea.CityName+"\n";
            }
            else if(CurrentCity==Mehadia.CityID)
            {
                Cost+=Mehadia.PathCost1;
                Result+=Mehadia.CityName+"\n";
            }
            else if(CurrentCity==Craiova.CityID)
            {
                Cost+=Craiova.PathCost1;
                Result+=Craiova.CityName+"\n";
            }
            else if(CurrentCity==Doberta.CityID)
            {
                Result+=Doberta.CityName+"\n";
                Cost+=Doberta.PathCost1;
            }
            else if(CurrentCity==Pitesti.CityID)
            {
                Cost+=Pitesti.PathCost1;
                Result+=Pitesti.CityName+"\n";
            }
            else if(CurrentCity==Bucharest.CityID)
            {
                Cost+=Bucharest.PathCost1;
                Result+=Bucharest.CityName+"\n";
                cout<<Result;
                cout<<"\n Path Cost : "<<Cost<<endl;
                exit(0);
            }

            Node<int> *Temp=ConnectedCities[CurrentCity].GetHead();
            while(Temp!=0)
            {
                if(Visited[Temp->GetData()] == false)
                {
                    DFSUtil(Temp->GetData(),Visited,Cost,Result);
                }
                Temp=Temp->GetNext();
            }
        }
        void DepthFirstSearch(int Start,int End)
        {
            bool *Visited=new bool[V];
            string Result="\0";
            for (int i=0;i<V;i++)
            {
                Visited[i]=false;
            }
            DFSUtil(Start,Visited,0,Result);
        }
        void A_StarSearch(int CurrentCity,int End)
        {
            int Cost=0;
            string Result="\0";
            MinHeap Heap(13);
            int MatchCity[14];
            for(int i=0;i<14;i++)
            {
                MatchCity[i]=1;
            }
            while(CurrentCity!=End)
            {
                if(CurrentCity==Arad.CityID)
                {
                    Cost+=Arad.PathCost1;
                    Result+=Arad.CityName+"\n";
                }
                else if(CurrentCity==Timisoara.CityID)
                {
                    Cost+=Timisoara.PathCost1;
                    Result+=Timisoara.CityName+"\n";
                }
                else if(CurrentCity==Sibiu.CityID)
                {
                    Cost+=Sibiu.PathCost1;
                    Result+=Sibiu.CityName+"\n";
                }
                else if(CurrentCity==Zerind.CityID)
                {
                    Cost+=Zerind.PathCost1;
                    Result+=Zerind.CityName+"\n";
                }
                else if(CurrentCity==Lugoj.CityID)
                {
                    Cost+=Lugoj.PathCost1;
                    Result+=Lugoj.CityName+"\n";
                }
                else if(CurrentCity==Rimincu.CityID)
                {
                    Cost+=Rimincu.PathCost1;
                    Result+=Rimincu.CityName+"\n";
                }
                else if(CurrentCity==Fagaras.CityID)
                {
                    Cost+=Fagaras.PathCost1;
                    Result+=Fagaras.CityName+"\n";
                }
                else if(CurrentCity==Oradea.CityID)
                {
                    Cost+=Oradea.PathCost1;
                    Result+=Oradea.CityName+"\n";
                }
                else if(CurrentCity==Mehadia.CityID)
                {
                    Cost+=Mehadia.PathCost1;
                    Result+=Mehadia.CityName+"\n";
                }
                else if(CurrentCity==Craiova.CityID)
                {
                    Cost+=Craiova.PathCost1;
                    Result+=Craiova.CityName+"\n";
                }
                else if(CurrentCity==Doberta.CityID)
                {
                    Result+=Doberta.CityName+"\n";
                    Cost+=Doberta.PathCost1;
                }
                else if(CurrentCity==Pitesti.CityID)
                {
                    Cost+=Pitesti.PathCost1;
                    Result+=Pitesti.CityName+"\n";
                }
                else if(CurrentCity==Bucharest.CityID)
                {
                    Cost+=Bucharest.PathCost1;
                    Result+=Bucharest.CityName+"\n";
                }
                Node<int> *Temp=ConnectedCities[CurrentCity].GetHead();
                while(Temp!=0)
                {
                    int CityNewID=Temp->GetData();
                    int TempCost=0;
                    if(CityNewID==Arad.CityID)
                    {
                        TempCost=Arad.PathCost1+Arad.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[1]=TempCost;
                    }
                    else if(CityNewID==Timisoara.CityID)
                    {
                        TempCost=Timisoara.PathCost1+Timisoara.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[2]=TempCost;
                    }
                    else if(CityNewID==Sibiu.CityID)
                    {
                        TempCost=Sibiu.PathCost1+Sibiu.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[3]=TempCost;
                    }
                    else if(CityNewID==Zerind.CityID)
                    {
                        TempCost=Zerind.PathCost1+Zerind.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[4]=TempCost;
                    }
                    else if(CityNewID==Lugoj.CityID)
                    {
                        TempCost=Lugoj.PathCost1+Lugoj.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[5]=TempCost;
                    }
                    else if(CityNewID==Rimincu.CityID)
                    {
                        TempCost=Rimincu.PathCost1+Rimincu.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[6]=TempCost;
                    }
                    else if(CityNewID==Fagaras.CityID)
                    {
                        TempCost=Fagaras.PathCost1+Fagaras.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[7]=TempCost;
                    }
                    else if(CityNewID==Oradea.CityID)
                    {
                        TempCost=Oradea.PathCost1+Oradea.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[8]=TempCost;
                    }
                    else if(CityNewID==Mehadia.CityID)
                    {
                        TempCost=Mehadia.PathCost1+Mehadia.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[9]=TempCost;
                    }
                    else if(CityNewID==Craiova.CityID)
                    {
                        TempCost=Craiova.PathCost1+Craiova.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[10]=TempCost;
                    }
                    else if(CityNewID==Doberta.CityID)
                    {
                        TempCost=Doberta.PathCost1+Doberta.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[11]=TempCost;
                    }
                    else if(CityNewID==Pitesti.CityID)
                    {
                        TempCost=Pitesti.PathCost1+Pitesti.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[12]=TempCost;
                    }
                    else if(CityNewID==Bucharest.CityID)
                    {
                        TempCost=Bucharest.PathCost1+Bucharest.H_Cost;
                        Heap.insertKey(TempCost);
                        MatchCity[13]=TempCost;
                    }
                    Temp=Temp->GetNext();
                }
                int MinCostCity=Heap.extractMin();
                for(int i=1;i<14;i++)
                {
                    if(MinCostCity==MatchCity[i])
                    {
                        CurrentCity=i;
                        break;
                    }
                }
            }
            if(Result.find("Fagaras")>-1)
            {
                Cost+=Bucharest.PathCost1;
            }
            else
            {
                Cost+=Bucharest.PathCost2;
            }
            Result+=" Bucharest";
            cout<<Result<<"\n\n Path Cost : "<<Cost;
        }
};

int	main( )
{
    RomaniaMap M1(13);

    // City Connections

    M1.AddCity(Arad.CityID,Timisoara.CityID);
    M1.AddCity(Arad.CityID,Sibiu.CityID);
    M1.AddCity(Arad.CityID,Zerind.CityID);
    M1.AddCity(Timisoara.CityID,Lugoj.CityID);
    M1.AddCity(Sibiu.CityID,Rimincu.CityID);
    M1.AddCity(Sibiu.CityID,Fagaras.CityID);
    M1.AddCity(Sibiu.CityID,Oradea.CityID);
    M1.AddCity(Zerind.CityID,Oradea.CityID);
    M1.AddCity(Lugoj.CityID,Mehadia.CityID);
    M1.AddCity(Rimincu.CityID,Craiova.CityID);
    M1.AddCity(Rimincu.CityID,Pitesti.CityID);
    M1.AddCity(Fagaras.CityID,Bucharest.CityID);
    M1.AddCity(Mehadia.CityID,Doberta.CityID);
    M1.AddCity(Doberta.CityID,Craiova.CityID);
    M1.AddCity(Craiova.CityID,Pitesti.CityID);
    M1.AddCity(Pitesti.CityID,Bucharest.CityID);

    cout<<"\n \xDB Romania Map\n\n";

    cout<<" A* Search from Arad to Bucharest... \n\n";
    M1.A_StarSearch(Arad.CityID,Bucharest.CityID);
    cout<<endl<<endl;

    cout<<" Breadth First Traversal from Arad to Bucharest... \n\n";
    M1.BreadthFirstSearch(Arad.CityID,Bucharest.CityID);

    cout<<"\n Depth First Traversal from Arad to Bucharest... \n\n";
    M1.DepthFirstSearch(Arad.CityID,Bucharest.CityID);
    cout<<endl<<endl;

    return 0;
}
