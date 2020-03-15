#include <iostream>
#include <vector>
#include <stack>
#define INFINITY 0xFFFFFFFF
using namespace std;
namespace Mido
{
	namespace Utility
	{
		class Graph
		{
		public:
			typedef stack<unsigned> path_t;
			typedef vector<path_t>  path_list;		
			typedef vector< vector<double> > dim_t; 

			Graph();
			Graph( const dim_t& array );
			Graph( const double **array , unsigned N );
			~Graph();								
			int KSP( unsigned k , path_list& kpaths );

		private:
			double dijk( int* paths , unsigned start = 0 , unsigned end = 0 );
			double dijk( int* paths , double* dists );
			unsigned addNode( unsigned ni , int preni );		

		private:
			unsigned Num;
			unsigned _size; 
			dim_t    _array; 
				
		};
	}
}
using namespace Mido::Utility;
Graph::Graph() : Num(0), _size(0)
{
}

Graph::Graph(const dim_t& array)
{
	Num = _size = array.size();
	_array.resize(_size);
	for(int i=0;i<_size;i++)
	{
		_array[i].resize(_size);
		for(int j=0;j<_size;j++)
			_array[i][j] = array[i][j];
	}
}

Graph::Graph(const double **array, unsigned N) : Num(N), _size(N)
{	
	_array.resize(_size);
	for(int i=0;i<_size;i++)
	{
		_array[i].resize(_size);
		for(int j=0;j<_size;j++)
			_array[i][j] = array[i][j];
	}
	
}

Graph::~Graph()
{	
}

int Graph::KSP( unsigned k ,  path_list& kpaths )
{	
	vector<int> Path, Prime, Base;
	vector<double> Dist;
	Path.resize(_size); 
	Prime.resize(_size);
	Base.resize(_size);
	Dist.resize(_size);
	for(int i=0;i<_size;i++)
	{ Prime[i] = -1; Base[i] = i; }
		
	if( dijk(&Path[0],&Dist[0]) < 0 ) return 0;
	path_t path; 
	int j = _size - 1;	
	while(j>=0)
	{		
		path.push(j); j=Path[j];			
	}
	kpaths.push_back(path); 

	int ki = 1;
	while( ki < k )
	{
		unsigned nh = 0;
		while( path.size() )
		{
			unsigned node = path.top(); path.pop();
			int count = 0;
			for( int i=0; i<_size; i++ )
			{
				if( _array[i][node] >= 0 ) count++;
				if( count > 1 ) break;
			}
			
			if( count > 1 ) { nh = node; break; }
		}

		if( !nh ) break;

		unsigned ni = 0;
		if( Prime[nh] < 0 )
		{
			unsigned nh1 = addNode(nh,Path[nh]);

			double min_dist = (unsigned)INFINITY;
			int min_node = -1;
			for(int i=0;i<_size-1;i++)
			{
				if( Dist[i] + (unsigned)_array[i][nh1] < min_dist )
				{
					min_dist = Dist[i] + _array[i][nh1];
					min_node = i;
				}
			}
			
			Dist.push_back(min_dist);
			Path.push_back(min_node);
			Prime.push_back(-1);
			Prime[nh] = nh1;

			unsigned basei = nh;
			while(basei != Base[basei])
				basei = Base[basei];
			Base.push_back(basei);

			if(path.size())
			{ ni = path.top(); path.pop(); }
		}
		else
		{
			while( path.size() )
			{
				ni = path.top(); path.pop();
				if(Prime[ni] < 0) break;				
			}
		}		

		while(ni)
		{
			unsigned ni1 = addNode(ni,Path[ni]);
			if(Prime[Path[ni]]>=0)				
				_array[Prime[Path[ni]]][ni1] = _array[Path[ni]][ni];		

			double min_dist = (unsigned)INFINITY;
			int min_node = -1;
			for(int i=0;i<_size-1;i++)
			{
				if( Dist[i] + (unsigned)_array[i][ni1] < min_dist )
				{
					min_dist = Dist[i] + _array[i][ni1];
					min_node = i;
				}
			}
			
			Dist.push_back(min_dist);
			Path.push_back(min_node);
			Prime.push_back(-1);
			Prime[ni] = ni1;

			unsigned basei = ni;
			while(basei != Base[basei])
				basei = Base[basei];
			Base.push_back(basei);

			if( !path.size() ) break;
			ni = path.top(); path.pop();			
		}

		if( !ni ) ni = nh;
		path_t temp;		
		int j = Prime[ni];
		while(j>=0)
		{		
			path.push(j); temp.push(Base[j]); j=Path[j];
		}
		if(temp.size()<2) break; 
		kpaths.push_back(temp);

		ki++;
	}	
	
	return ki;
}

double Graph::dijk( int* paths , unsigned start , unsigned end )
{	
	int* Used = new int[Num];		   
	double* Dist = new double[Num];     
	
	unsigned i;
	for(i=0;i<Num;i++)
	{
		paths[i]= -1;	
		Used[i] = 0;
		Dist[i] = (_array[start][i] < 0.0) ? INFINITY : _array[start][i]; 
	}	
	Used[start] = 1;
	
	unsigned count = 0;	
	while(count++ < Num)
	{		
		int min_node = -1;
		double min_dist = (unsigned)INFINITY;

		for(i=0;i<Num;i++)
		{
			if(Used[i] > 0)continue;
			
			if(Dist[i] < min_dist)
			{
				min_dist = Dist[i];
				min_node = i;
			}
		}
		if(min_dist == INFINITY)break;

		if(min_node >= 0)
		{			
			Used[min_node]  = 1;
			Dist[min_node]  = min_dist;			
		}
		if(min_node >= (int)Num-1)break;

		for(i=0;i<Num;i++)
		{
			if( Used[i] > 0)continue;

			double w = (unsigned)_array[min_node][i];
			if( min_dist + w < Dist[i] )
			{
				Dist[i] = min_dist + w;
				paths[i] = min_node;
			}
		}       
	}	

	double mdist = Dist[Num-1];
	if( end != start && end < Num)
		mdist = Dist[end];

	delete[] Used;
	delete[] Dist;

	return (signed)mdist;
}

double Graph::dijk( int* paths , double* dists )
{	
	int* Used = new int[Num]; 
	double* Dist = dists;
	
	unsigned i;
	for(i=0;i<Num;i++)
	{
		paths[i]= -1;	
		Used[i] = 0;
		Dist[i] = (_array[0][i] < 0.0) ? INFINITY : _array[0][i]; 
	}	
	Used[0] = 1;
	
	unsigned count = 0;	
	while(count++ < Num)
	{		
		int min_node = -1;
		double min_dist = (unsigned)INFINITY;

		for(i=0;i<Num;i++)
		{
			if(Used[i] > 0)continue;
			
			if(Dist[i] < min_dist)
			{
				min_dist = Dist[i];
				min_node = i;
			}
		}
		if(min_dist == INFINITY)break;

		if(min_node >= 0)
		{			
			Used[min_node]  = 1;
			Dist[min_node]  = min_dist;			
		}
		if(min_node >= (int)Num-1)break;

		for(i=0;i<Num;i++)
		{
			if( Used[i] > 0)continue;

			double w = (unsigned)_array[min_node][i];
			if( min_dist + w < Dist[i] )
			{
				Dist[i] = min_dist + w;
				paths[i] = min_node;
			}
		}       
	}

	delete[] Used;
	return (signed)Dist[Num-1];
}

unsigned Graph::addNode(unsigned ni,int preni)
{
	vector<double> newRow;
	for(int i=0;i<_size;i++)
	{
		if(i != preni)
			_array[i].push_back(_array[i][ni]);
		else
			_array[i].push_back(-1);

		newRow.push_back(-1);
	}
	newRow.push_back(-1);
	_array.push_back(newRow);

	return _size++;
}
int main(int argc, char** argv)
{	
	int num;
	cin >> num;
	int matrix[num][num];
	for(int i = 0; i < num ; i++)
		for(int j = 0; j < num ; j++)
			matrix[i][j] = -1;
	int edge;
	cin >> edge;
	while( edge > 0 ){
		int count = 0, start, end, weight, input;
		while(cin >> input){
			if( count == 0 ){
				start = input;
				count++;
			}
			else if( count == 1 ){
				end = input;
				count++;
			}
			else if( count == 2 ){
				weight = input;
				count++;
			}
			if(cin.get() == '\n')
			break;
		}
		matrix[start-1][end-1] = weight;
		edge-= 1;
	}
	double** array = new double*[num];
	for(int i=0;i<num;i++)
		array[i] = new double[num];
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			array[i][j] = matrix[i][j];
	int max;
	cin >> max;
	
	Graph graph((const double**)array,num);

	// Find the k shortest paths
	Graph::path_list paths;
	graph.KSP(max,paths);
	cout << endl;
	
	for(unsigned i=0;i<paths.size();i++)	// output the k shortest paths.
	{
		cout << 1 << " ";
		while(paths[i].size())
		{
			cout << paths[i].top() + 1 << " ";
			paths[i].pop();
		}
		cout << endl;
	}

	for(int i=0;i<num;i++)
		delete[] array[i];
	delete[] array;

	return 0;
}
