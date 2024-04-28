#include<iostream>
#include<vector>
#include<random>

template<typename T>
void bubbleSort(std::vector<T>& v)
{
    for(size_t i=0; i<v.size(); ++i)
    {
        for(size_t j=0; j<v.size()-i-1; ++j)
        {
            if(v[j]>v[j+1])
            {
                std::swap(v[j], v[j+1]);
            }
        }
    }
}

template <typename T>
void insertionSort(std::vector<T>& v)
{
    for(size_t i=1; i<v.size(); ++i)
    {
        T key = v[i];
        size_t j = i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

template <typename T>
void selectionSort (std::vector<T>& v)
{
    for(size_t i=0; i<v.size()-1; ++i)
    {
        size_t minIndex = i;
        for(size_t j=i+1; j<v.size(); ++j)
        {
            if(v[j]<v[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(v[i], v[minIndex]);
    }
}

template <typename T>
void quickSort(std::vector<T>& v)
{
    if(v.size()<=1) return;
    size_t pivotIndex = v.size()/2;
    T pivot = v[pivotIndex];
    std::vector<T> left;
    std::vector<T> right;
    for(size_t i=0; i<v.size(); ++i)
    {
        if(i==pivotIndex) continue;
        if(v[i]<pivot)
        {
            left.push_back(v[i]);
        }
        else
        {
            right.push_back(v[i]);
        }
    }
    quickSort(left);
    quickSort(right);
    size_t k=0;
    for(size_t i=0; i<left.size(); ++i)
    {
        v[k++] = left[i];
    }
    v[k++] = pivot;
    for(size_t i=0; i<right.size(); ++i)
    {
        v[k++] = right[i];
    }
}

template <typename T>
void mergeSort(std::vector<T>& v)
{
    if(v.size()<=1) return;
    size_t mid = v.size()/2;
    std::vector<T> left(v.begin(), v.begin()+mid);
    std::vector<T> right(v.begin()+mid, v.end());
    mergeSort(left);
    mergeSort(right);
    size_t i=0, j=0, k=0;
    while(i<left.size() && j<right.size())
    {
        if(left[i]<right[j])
        {
            v[k++] = left[i++];
        }
        else
        {
            v[k++] = right[j++];
        }
    }
    while(i<left.size())
    {
        v[k++] = left[i++];
    }
    while(j<right.size())
    {
        v[k++] = right[j++];
    }
}

template<typename T>
bool isSorted(const std::vector<T>& v )
{
    for(size_t i=0; i<v.size()-1;++i)
      if(v.at(i)>v.at(i+1)) return false;
    return true;
}

int main()
{
 std::vector<int> v1{23,45,12,7,6,9,3};
 std::vector<int> v3{4,3,2,1,7,8,9,6};
 std::vector<int> v4{3,6,1,7,9,8,2,4,5};
 std::vector<int> v5{22,44,33,11,66,55,88,77};
 std::vector<int> v2{9,2,3,1,7,8,6,4,5};
 bubbleSort(v1);
 insertionSort(v2);
 selectionSort(v3);
 quickSort(v4);
 mergeSort(v5);
 std::vector<std::vector<int>> vectors;
 vectors.push_back(v1);
 vectors.push_back(v2);
 vectors.push_back(v3);
 vectors.push_back(v4);
 vectors.push_back(v5);
 int sorted=0;
 for (auto v: vectors)
     if( isSorted(v)) ++sorted;
 std::cout<<"sorted :"<<sorted<<"\n";
 return 0;
}