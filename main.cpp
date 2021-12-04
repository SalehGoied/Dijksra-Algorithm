#include <iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"Dijkstra's Algorithm"<<endl;
    cout<<"====================="<<endl<<endl;
    //u -> Number of vertices
    int u = 0;
    cout<<"Number of vertices:";
    cin>>u;
    long long l[u][u] = {0};
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
            l[i][j] = -1;
    }
    cout<<"if there is no edge between Xi and Xj enter 0"<<endl<<endl;
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            if (i == j)
                l[i][i] = 0;
            else if (l[i][j] == -1)
            {
                cout<<"weight of edge between X" << i+1 << " and X" << j+1 << ":";
                cin>>l[i][j];
                if (l[i][j] == 0)
                    l[i][j] = 2147483647;
                l[j][i] = l[i][j];
            }
        }
    }

    do{
        int source = 0;
        cout<<"source = ";
        cin>>source;
        long long d[u],path[u];
        bool check[u] = {false};

        for (int i = 0; i < u; i++)
        {
            d[i] = 2147483647;
            path[i] = 2147483647;
        }
        source--;
        int source_const = source;
        d[source] = 0;
        path[source] = source;
        check[source] = true;
        int counter = u-1;
        while(counter--)
        {
            for (int i = 0; i < u; i++)
            {
                if (!check[i])
                {
                    if (d[source] + l[i][source] < d[i])
                        path[i] = source;
                    d[i] = min(d[i], d[source] + l[i][source]);
                }
            }
            int min_l = 2147483647;
            for (int i = 0; i < u; i++)
            {
               if (!check[i])
                {
                    if (d[i] < min_l)
                    {
                        source = i;
                        min_l = d[i];
                    }
                }
            }
            check[source] = true;
        }
        cout<<endl;
        for (int i = 0; i < u; i++)
        {
            cout<<"Distance of X"<<i+1<<" = "<<d[i]<<endl;

            int q = i;
            string pathX = "X" + to_string(q+1);
            do{

                    if (q == source_const)
                    {
                        break;
                    }
                    else
                    {
                        pathX = "X" + to_string(path[q]+1)+" => " + pathX;
                    }
                    q = path[q];
            }while(true);
            cout<<"path: "<<pathX<<endl<<endl;
        }
        cout<<endl;
        cout<<"another source?(y or n): ";
        string ag = "";
        cin>>ag;
        if (ag != "y")
            break;

    }while(true);

    return 0;
}
