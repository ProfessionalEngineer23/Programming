// Name: Niki Spasov, Niki Mardari
// Student number: B00161794, B00159642
// Email Address: B00161794@mytudublin.ie, B00159642@mytudublin.ie
// Date: 08/03/2026
// Module: ELTC H3028 Java and Algorithms
// Purpose of code: Skeleton for MileageRecord method

import java.util.List;
import java.util.Scanner;
import java.time.LocalDate;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.time.format.DateTimeFormatter;
import java.util.Comparator;

public class Mileage {

	public static void main(String[] args) {
		if(args.length == 0){
			System.out.println("Error no filename provided");
			return;
		}
		String filename = args[0];
		
		List<MileageRecord> records = readRecords(filename);
		sortRecords(records);
		computeEfficiencies(records);
		 
		//create the object that will capture the stats
		EfficiencyStatsTask task = new EfficiencyStatsTask(records);
		Thread t = new Thread(task);
		t.start();
		
		try {
			t.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println("Min efficiency: " + task.getMin());
		System.out.println("Max efficiency: " + task.getMax());
		System.out.println("Avg efficiency: " + task.getAvg());
	}

	//read filename from command line arguments
	public static List<MileageRecord> readRecords(String filename) {
		List<MileageRecord> records = new ArrayList<>();
		 
		File f = new File(filename);
		
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		
		//try creating a new scanner for the contents of the file
		try(Scanner sc1 = new Scanner(f)) {
			// First check if scanner has next line
			//skip first header line (not an actual record)
			if(sc1.hasNextLine()){
				sc1.nextLine();
			}
			// Otherwise, return empty records
			else {
			return records; 
			}
			//first scanner scans in each individual line
			while(sc1.hasNextLine()){
				String data = sc1.nextLine();
				//if the string (aka the line) is empty skip this loop iteration
				if (data.trim().isEmpty()) continue;
				//try creating 2nd scanner to parse the contents of the line
				try(Scanner sc2 = new Scanner(data)){
					//scan the String representing the date
					String dateString = sc2.next();
					//convert the String to LocalDate type date using the formatter
					LocalDate date = LocalDate.parse(dateString, formatter);
					int kilometers = sc2.nextInt();
					double liters = sc2.nextDouble();
					//add a new MileageRecord object to the records list
					records.add(new MileageRecord(date, kilometers, liters));
				}
			}
		} catch(FileNotFoundException e) {
			System.out.println("Error file not found");
		}
		return records;
	}
	
	//sort records based on date
    public static void sortRecords(List<MileageRecord> records) {
        records.sort(Comparator.comparing(MileageRecord::getDate));
    }
	
	//compute efficiencies
	public static void computeEfficiencies(List<MileageRecord> records) {
		for(int i = 1; i < records.size(); i++) {
			MileageRecord currentRecord = records.get(i);
			MileageRecord previousRecord = records.get(i-1);
			
			double distance = currentRecord.getKilometers() - previousRecord.getKilometers(); 
			double liters = currentRecord.getLiters();
			if(distance > 0) {
				double efficiency = (liters / distance) * 100;	
				currentRecord.setEfficiency(efficiency);
			} else { 
				currentRecord.setEfficiency(Double.NaN);
			}
		}
	}
}
