typedef struct
{
    string PID;
    int size;
} Partition;

vector<Partition> P;
int total_size, frag_space;

bool if_exists(string id)
{
    for (auto i : P)
        if (i.PID == id)
            return false;
        else
            return true;
    return true;
}

int InsertBest(string id, int size)
{

    if (frag_space < size)
        return false;

    // bool allocated = false;
    int best_fit = total_size + 1;
    int position = -1;

    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].PID == "#" && P[i].size >= size && P[i].size < best_fit)
        {
            if (P[i].size == size)
            {
                frag_space -= size;
                P[i].PID = id;
                return size;
            }
            best_fit = P[i].size;
            position = i;
        }
    }

    if (position < 0)
        return position;

    P[position].size -= size;
    P.insert(P.begin() + position, {id, size});
    frag_space -= size;
    return size;
}

void Delete(string id)
{
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].PID == id)
        {
            P[i].PID = "#";
            frag_space += P[i].size;
            if (i < P.size() - 1 && P[i + 1].PID == "#")
            {
                P[i].size += P[i + 1].size;
                P.erase(P.begin() + i + 1);
            }
            break;
        }
    }
    for (int i = 0; i < P.size() - 1; i++)
    {
        if (P[i].PID == "#" && P[i + 1].PID == "#")
        {
            P[i].size += P[i + 1].size;
            P.erase(P.begin() + i + 1);
        }
    }
}

int InsertFirst(string id, int size)
{
    // cout << "frag space : " << frag_space << "\n";
    if (frag_space < size)
        return false;

    // bool allocated = false;

    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].PID == "#" && P[i].size >= size)
        {
            if (P[i].size == size)
            {
                frag_space -= size;
                P[i].PID = id;
                return size;
            }
            P[i].size -= size;
            P.insert(P.begin() + i, {id, size});
            frag_space -= size;
            return size;
        }
    }

    return -1;
}

int InsertWorst(string id, int size){
    // cout << "frag space : " << frag_space << "\n";
    if (frag_space < size)
        return false;

    // bool allocated = false;

    int worst_size = 0;
    int position = -1;

    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].PID == "#" && P[i].size > worst_size)
        {
            // if(P[i].size == size){
            //     P[i].PID = id;
            //     return size;
            // }
            // P[i].size -= size;
            // P.insert(P.begin() + i, {id,size});
            // frag_space -= size;
            // return size;
            worst_size = P[i].size;
            position = i;
        }
    }

    if (worst_size < size)
        return -1;

    P[position].size -= size;
    P.insert(P.begin() + position, {id, size});
    frag_space -= size;
    return size;
}

void Display()
{
    cout << "\n";
    int partition = 1;
    for (auto i : P)
    {
        cout << "Partition " << partition++ << " ";
        if (i.PID == "#")
            cout << "is empty with size " << i.size;
        else
            cout << "has Process " << i.PID << " of size : " << i.size;
        cout << "\n";
    }
    cout << "\n";
}

int MVT(){
    cout << "Enter size : ";
    cin >> total_size;
    // total_size;
    frag_space = total_size;
    bool ok = true;
    P.push_back({"#", total_size});
    int y;
    cout << "1. First Fit\n2. Worst Fit\n3. Best Fit\n\nEnter option: ";
    cin >> y;
    while (ok)
    {
        cout << "1. Insert   2. Delete   3. Exit\nEnter option : ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter process ID : ";
            string id;
            cin >> id;
            cout << "Enter size : ";
            int size;
            cin >> size;
            int result ;//= InsertBest(id, size);
            if(y == 1) result = InsertFirst(id,size);
            else if(y == 2) result = InsertWorst(id,size);
            else if(y == 3) result = InsertBest(id,size);
            if (result > 0)
                cout << "Sucessfully allocated!\n";
            else if (result == 0)
                cout << "Not enough space!\n";
            else
                cout << "External fragmentation fault, could not allocate!\n";
            Display();
        }
        else if (op == 2)
        {
            cout << "Enter process ID : ";
            string id;
            cin >> id;
            Delete(id);
            Display();
        }
        else
        {
            Display();
            ok = false;
        }
    }
    P.clear();
    return 0;
}