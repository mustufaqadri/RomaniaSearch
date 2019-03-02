#include<iostream>
using namespace std;

class CityNode
{
    public:

        int CityID;
        string CityName;
        int H_Cost;
        int PathCost1;
        int PathCost2;

        CityNode(int ID,string Name,int HCost,int PCost1,int PCost2=0)
        {
            CityID=ID;
            CityName=Name;
            H_Cost=HCost;
            PathCost1=PCost1;
            PathCost2=PCost2;
        }
};
