#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR -1
#define false  0
#define true   1
#define MaxVertexNum 100
#define INFINITY     65535
#define MaxQueue 100
typedef int Vertex;
typedef int WeightType;
typedef int bool;

//边
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

//邻接点
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;            //下标
    WeightType Weight;      //边权重
    PtrToAdjVNode Next;     //指向下一个邻接点
};

//顶点
typedef struct VNode {
    PtrToAdjVNode FirstEdge;    //边表头指针
    // DataType Data;              //存顶点的户数据
}AdjList[MaxVertexNum];

//图结点
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

struct QNode {
    Vertex Data[MaxQueue];
    int rear;
    int front;
};
typedef struct QNode *Queue;

int IsEmptyQ(Queue PtrQ)
{
    return (PtrQ->front == PtrQ->rear);
}

void AddQ(Queue PtrQ, Vertex item)
{
    if((PtrQ->rear+1)%MaxQueue == PtrQ->front) {
        printf("Queue full");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MaxQueue;
    PtrQ->Data[PtrQ->rear] = item;
}

Vertex DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear) {
        printf("Queue Empty");
        return -1;
    } else {
        PtrQ->front = (PtrQ->front+1)%MaxQueue;
        return PtrQ->Data[PtrQ->front];
    }
}

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    //有向边
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    //向V1插入V2
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int Nv, i;

    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);

    scanf(" %d\n", &(Graph->Ne));
    if(Graph->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++) {
            scanf("%d %d %d\n", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

void PrintGraph(LGraph Graph)
{
    Vertex V;
    PtrToAdjVNode W;
    for(V=0;V<Graph->Nv;V++) {
        printf("%d:", V);
        for(W=Graph->G[V].FirstEdge;W;W=W->Next) {
            printf("[%3d %3d] ", W->AdjV, W->Weight);
        }
        printf("\n");
    }
}



/* 邻接表存储 - 拓扑排序算法 */
bool TopSort( LGraph Graph, Vertex TopOrder[], Vertex Earliest[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
    int Indegree[MaxVertexNum], cnt;
    Vertex V;
    PtrToAdjVNode W;

    Queue Q = (Queue)malloc(sizeof(struct QNode)*( Graph->Nv ));

    /* 初始化Indegree[] */
    for (V=0; V<Graph->Nv; V++)
        Indegree[V] = 0;

    /* 遍历图，得到Indegree[] */
    for (V=0; V<Graph->Nv; V++)
        for (W=Graph->G[V].FirstEdge; W; W=W->Next)
            Indegree[W->AdjV]++; /* 对有向边<V, W->AdjV>累计终点的入度 */

    /* 将所有入度为0的顶点入列 */
    for (V=0; V<Graph->Nv; V++)
        if ( Indegree[V]==0 ) {
            AddQ(Q, V);
            Earliest[V] = 0;         //起点为0
        }

    /* 下面进入拓扑排序 */
    cnt = 0;
    while( !IsEmptyQ(Q) ){
        V = DeleteQ(Q); /* 弹出一个入度为0的顶点 */
        TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */
        /* 对V的每个邻接点W->AdjV */
        for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
            if ( --Indegree[W->AdjV] == 0 ) {/* 若删除V使得W->AdjV入度为0 */
                AddQ(Q, W->AdjV); /* 则该顶点入列 */
                Earliest[W->AdjV] = Earliest[V] + W->Weight;
                // if((Earliest[V]+W->Weight)>Earliest[W->AdjV] && Earliest[W->AdjV])
                // Earliest[W->AdjV] = Earliest[V] + W->Weight;
            }
    } /* while结束*/

    if ( cnt != Graph->Nv )
        return false; /* 说明图中有回路, 返回不成功标志 */
    else
        return true;
}

int main()
{
    LGraph Graph;
    WeightType Earliest[MaxVertexNum];
    Vertex TopOrder[MaxVertexNum],V;
    int ret;

    Graph = BuildGraph();
    // PrintGraph(Graph);
    ret = TopSort(Graph, TopOrder, Earliest);
    if(ret == false) {
        printf("Impossible");
    } else if(ret == true) {
        int max = Earliest[0];
        for(int i=0;i<Graph->Nv;i++) {
            // printf("%d: [%d]\n", i, Earliest[i]);
            if(max < Earliest[i])
                max = Earliest[i];
        }
        printf("%d", max);
    }
    // printf("TopOrder:");
    // for(V=0;V<Graph->Nv;V++)
    //     printf("%d ", TopOrder[V]);
    // printf("\n");
    return 0;
}