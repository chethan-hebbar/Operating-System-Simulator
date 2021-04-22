int RR()
{
    cout << "This is Round robin CPU scheduling algorithm" << endl;
    struct process
    {
        int id;
        int at;
        int bt;
        int bt2;
    };
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    struct process p[n];
    int minTime = INT8_MAX;
    cout << "Enter the id, at and bt respectively: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].id >> p[i].at >> p[i].bt;
        p[i].bt2 = p[i].bt;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                swap(p[i], p[j]);
            }
        }
    }
    int timeQuanta = 2, check[n] = {0}, ct[n];
    int completed = 0;
    int i = 1;
    q.push(0);
    cout << "Enter the time quanta: " << endl;
    cin >> timeQuanta;
    int time = p[0].at;
    while (completed < n)
    {
        if (q.empty())
        {
            q.push(i);
            time = p[i].at;
            i++;
        }
        int j = q.front();
        q.pop();
        int slice = min(p[j].bt, timeQuanta);
        p[j].bt -= slice;
        if (time == 8)
        {
            cout << "Slice: " << slice << endl;
            cout << "BT " << p[j].bt << endl;
        }
        time += slice;
        while (i < n && p[i].at <= time)
        {
            q.push(i);
            i++;
        }
        if (p[j].bt == 0)
        {
            cout << "At time: " << time << " process " << p[j].id + 1 << " finishes execution" << endl;
            ct[j] = time;
            completed++;
        }
        else
        {
            q.push(j);
        }
    }
    int total_TAT = 0, total_WT = 0;
    int tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - p[i].at;
        wt[i] = tat[i] - p[i].bt2;
        total_TAT += tat[i];
        total_WT += wt[i];
    }
    cout << "Input:" << endl;
    cout << endl;
    cout << "P.No"
         << "\t"
         << "AT"
         << "\t"
         << "BT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt2 << endl;
    }
    cout << endl;
    cout << "Output from Round robin scheduling algorithm:" << endl;
    cout << endl;
    cout << "P.No"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "CT"
         << "\t"
         << "TAT"
         << "\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt2 << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    cout << endl;
    float avgTAT = (float)total_TAT / (float)n;
    float avgWT = (float)total_WT / (float)n;
    cout << "Average TAT: " << avgTAT << endl
         << "Average WT: " << avgWT << endl;
    return 0;
}