import java.util.*;

public class FirstComeFirstServe {

    public static void FCFS(int at[], int bt[], int n) {
        int ct[] = new int[n];
        int tat[] = new int[n];
        int wt[] = new int[n];

        // complition time
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += bt[i];
            ct[i] = temp;
        }
        // Turn around time and waiting time
        for (int j = 0; j < n; j++) {
            tat[j] = ct[j] - at[j];
            wt[j] = tat[j] - bt[j];
        }

        System.out.println("Solution: \n\n");
        System.out.println("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

        for (int k = 0; k < n; k++) {
            System.err.println((k + 1) + "\t" + at[k] + "\t" + bt[k] + "\t" + ct[k] + "\t" + tat[k] + "\t" + wt[k]);
        }
    }

    public static void main(String[] args) {
        int no_of_processes;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of Processes : ");
        no_of_processes = sc.nextInt();
        System.out.println("Enter Arival time and burst time for each process\n");
        int bt[] = new int[no_of_processes];
        int at[] = new int[no_of_processes];

        for (int i = 0; i < no_of_processes; i++) {
            System.out.println("Enter the Arrival time of process " + (i + 1));
            at[i] = sc.nextInt();
            System.out.println("Enter the Brust time of process " + (i + 1));
            bt[i] = sc.nextInt();
        }
        FCFS(at, bt, no_of_processes);
        sc.close();
    }
}

// at[]={0,1,5,6}
// bt[]={2,2,3,4}