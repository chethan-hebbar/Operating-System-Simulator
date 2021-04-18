int LRJF()
{
    cout << "This is SRJF CPU scheduling algorithm" << endl;
    struct process
    {
        int id;
        int at;
        int bt;
        int bt2;
        int in_queue;
        int completed;
        int ct;
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
        p[i].in_queue = 0;
        p[i].completed = 0;
        p[i].ct = 0;
        p[i].bt2 = p[i].bt;
    }
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
    int timeQuanta = 1;
    int completed = 0;
    int time = p[0].at;
    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].in_queue == 0 && p[i].completed == 0 && p[i].at <= time)
            {
                p[i].in_queue = 1;
                cout << "At time= " << time << " process " << i << " is enqueued " << endl;
            }
        }
        int maxBT = -1, minBTP = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].in_queue == 1 && p[i].completed == 0 && p[i].bt > maxBT)
            {
                maxBT = p[i].bt;
                minBTP = i;
            }
        }
        if (minBTP != -1)
        {
            int cut = min(timeQuanta, p[minBTP].bt);
            cout << "At time= " << time << " process " << minBTP << " is processed for time= "
                 << cut << endl;
            p[minBTP].bt -= cut;
            time += cut;
            if (p[minBTP].bt == 0)
            {
                cout << "At time= " << time << " process " << minBTP << " is completed " << endl;
                completed++;
                p[minBTP].completed = 1;
                p[minBTP].ct = time;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (p[i].in_queue == 0 && p[i].completed == 0)
                {
                    time = p[i].at;
                    break;
                }
            }
        }
    }
    int tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        tat[i] = p[i].ct - p[i].at;
        wt[i] = tat[i] - p[i].bt2;
        cout << wt[i] << endl;
    }
    return 0;
}