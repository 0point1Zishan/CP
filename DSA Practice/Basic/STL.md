# STL

### Rotate function:
```cpp
rotate(v.begin(), v.begin()+1, v.end())     // 1 times left rotate
rotate(v.begin(), v.begin()+3-1, v.end());  // 1 times right rotate
```

### String find:
```cpp
if(s.find(t) != string::npos){
    cout << "t found in s";
}
else{
    cout << "not found";
}
```