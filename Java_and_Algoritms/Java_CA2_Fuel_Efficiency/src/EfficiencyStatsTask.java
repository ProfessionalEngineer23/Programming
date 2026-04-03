// Name: Niki Spasov, Niki Mardari
// Student number: B00161794, B00159642
// Email Address: B00161794@mytudublin.ie, B00159642@mytudublin.ie
// Date: 06/03/2026
// Module: ELTC H3028 Java and Algorithms
// Purpose of code: EfficiencyStatsTask Runnable class containing the definitions of the overriden run() method that executes on a seperate thread

import java.util.List;

//implements Runnable so the run() method can execute in its own thread
public class EfficiencyStatsTask implements Runnable {
    private List<MileageRecord> records;
	
	public EfficiencyStatsTask(List<MileageRecord> records) {
		this.records = records;
	}
	
	private double min;
    private double max;
    private double avg;

	
	public void run() {
		//initialise min as a very large value for comparison 
		min = Double.POSITIVE_INFINITY;
		//initialise max as a very small value for comparison
		max = Double.NEGATIVE_INFINITY;
		avg = 0;
		// Sum to store total efficiency value for average calculation
		double sum = 0;
		// Count for the amount of efficiencies 
		int count = 0;

		// Loop through each efficiency starting from 1 because element at 0 is Nan,
		// In each iteration it compares the efficiency value to min and max and decides which one is smaller or larger
		// This is a Linear scan algorithm with o(n) complexity so the more values, the slower it gets
		for(int i = 1; i < records.size(); i++) {
			MileageRecord current = records.get(i);

			// Get current indexed efficiency value
			double efficiency = current.getEfficiency();

			// Checking if value is not Nan to avoid errors
			if (!Double.isNaN(efficiency)) {
				// Finding min efficiency 
				if(efficiency < min) { 
					min = efficiency; 
				}
				// Finding max efficiency
				if(efficiency > max) {
					max = efficiency;
				}
				//increment count with each loop iteration
				count++;
				// Sum all efficiency values
				sum += efficiency;
			}
		}
		// Avoiding division by 0
		if(count > 0) {
			avg = sum / count;
		} 
		// Otherwise avg is set as Nan
		else {
			avg = Double.NaN;
			System.out.println("Bad data!");
		}
	}

	// Helpers for getting private values to other methods  
    public double getMin() { 
        return min;
    }

    public double getMax() { 
        return max;
    }

    public double getAvg() { 
        return avg;
    }
  


}
