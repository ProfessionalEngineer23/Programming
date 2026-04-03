// Name: Niki Spasov, Niki Mardari
// Student number: B00161794, B00159642
// Email Address: B00161794@mytudublin.ie, B00159642@mytudublin.ie
// Date: 07/03/2026
// Module: ELTC H3028 Java and Algorithms
// Purpose of code: Testing harness for the readRecords(), sortRecords(), computeEfficiencies() and efficiencyStatsTask() methods

import java.util.List;

public class MileageTestHarness {

    public static void main(String[] args) {
		//check for user provided arguments
        if (args.length == 0) {
            System.out.println("No filename provided");
            return;
        }

        String filename = args[0];

		testReadRecords(filename);
        testSortRecords(filename);
        testComputeEfficiencies(filename);
        testEfficiencyStatsTask(filename);
    }


	//test for the readRecords() method definition stored in Mileage.java
	//expected output for testReadRecords() using mileage_tiny.txt:
    /*Number of records read: 4
	MileageRecord: date= 2025-01-02, kilometers= 24886, liters= 27.59, efficiency= Null
	MileageRecord: date= 2025-01-09, kilometers= 25319, liters= 29.55, efficiency= Null
	MileageRecord: date= 2025-01-23, kilometers= 25740, liters= 28.98, efficiency= Null
	MileageRecord: date= 2025-01-16, kilometers= 26141, liters= 27.13, efficiency= Null
	*/
   private static void testReadRecords(String filename) {
        System.out.println("Records read in from the file: ");

        List<MileageRecord> records = Mileage.readRecords(filename);

        System.out.println("Number of records read: " + records.size());
        for (MileageRecord record : records) {
            System.out.println(record);
        } 
    }
	
	//test for sortRecords() method, the definition is stored in Mileage.java
    /*expected output for testSortRecords() using mileage_tiny.txt:
	Records after sorting:
	2025-01-02 24886 27.59
	2025-01-09 25319 29.55
	2025-01-16 25740 28.98
	2025-01-23 26141 27.13
	*/
   private static void testSortRecords(String filename) { 

        List<MileageRecord> records = Mileage.readRecords(filename);
        Mileage.sortRecords(records);

        System.out.println("\nRecords after sorting:");
        for (MileageRecord record : records) {
            System.out.println(record.getDate() + " " + record.getKilometers() + " " + record.getLiters());
        } 
    }
	
	//test for computeEfficiencies() method, the definition stored in Mileage.java
	/*expected output for testComputeEfficiencies() using mileage_tiny.txt:
	Efficiencies:
	6.82
	6.88
	6.77
	*/
	private static void testComputeEfficiencies(String filename) { 
		
		List<MileageRecord> records = Mileage.readRecords(filename);
		Mileage.sortRecords(records);
		Mileage.computeEfficiencies(records);
		
		System.out.println("\nEfficiencies:");
		for(int i = 0; i < records.size(); i++) {
			MileageRecord current = records.get(i);
			System.out.println(current.getEfficiency());
		}
	}

	//efficiencyStatsTask() method definition stored in EfficiencyStatTask.java
	/*expected output for testEfficiencyStatsTask() using mileage_tiny.txt:
	test for EfficiencyStatsTask:
	Min = 6.77
	Max = 6.88
	Avg = 6.82
	Count = 3
	*/
    private static void testEfficiencyStatsTask(String filename) {
        System.out.println("\nEfficiency statistics:");

        List<MileageRecord> records = Mileage.readRecords(filename);
        Mileage.sortRecords(records);
        Mileage.computeEfficiencies(records);

        EfficiencyStatsTask task = new EfficiencyStatsTask(records);
        Thread thread = new Thread(task);

        try {
            thread.start();
            thread.join();
        } catch (InterruptedException e) {
            System.out.println("Test interrupted.");
            return;
        }

        System.out.println("Min = " + task.getMin());
		System.out.println("Max = " + task.getMax());
		System.out.println("Avg = " + task.getAvg());
    }
}