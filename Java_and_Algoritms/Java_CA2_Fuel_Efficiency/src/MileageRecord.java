// Name: Niki Spasov, Niki Mardari
// Student number: B00161794, B00159642
// Email Address: B00161794@mytudublin.ie, B00159642@mytudublin.ie
// Date: 06/03/2026
// Module: ELTC H3028 Java and Algorithms
// Purpose of code: Skeleton for MileageRecord class contains definitions of the MileageRecord objects and has getters for each record member

import java.time.LocalDate;
 
public class MileageRecord {
	
	private LocalDate date;
	private int kilometers;
	private double liters;
	private double efficiency;
	 
	//constructor
	public MileageRecord(LocalDate date, int kilometers, double liters) {
		this.date = date;
		this.kilometers = kilometers;
		this.liters = liters;
		this.efficiency = Double.NaN;
	}
	
	public LocalDate getDate() { 
		return date;
	}
	
	public int getKilometers() {
		return kilometers;
	}
	
	public double getLiters() {
		return liters;
	}
	
	public double getEfficiency() {
		return efficiency;
	}
	
	public void setEfficiency(double efficiency) {
		this.efficiency = efficiency;
	}
	
	public String toString() {
		return ("Date: " + date + ", kilometers: " + kilometers + ", liters: " + liters + ", efficiency: " + efficiency);
	}
	
}