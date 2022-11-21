package work.account;
import java.util.Objects;

import work.account.Employee;

public class Manager extends Employee{
    private double bonus;

    public Manager(String name, double s, int year, int month, int day){
        super(name, s, year, month, day);
        bonus = 0;
    }
    public double getBonus(){
        return bonus;
    }
    public void setBonus(double newBonus){
        bonus = newBonus;
    }
    public double getSalary(){
        return super.getSalary() + bonus;
    }

    public boolean equals(Object other){
        if (!super.equals(other))
            return false;
        var otherManager = (Manager) other;
        return bonus == otherManager.bonus;
    }
    public int hashCode(){
        return Objects.hash(super.hashCode(), bonus);
    }
    public String toString(){
        return super.toString() + "[bonus=" + bonus + "]";
    }

    public static void main(String[] args){
        Manager harry = new Manager("Harry Stamford", 50000, 1990, 10, 19);
        harry.setBonus(5000);
        System.out.println(harry.getName() + " " + 
                            harry.getSalary() + " " + 
                            harry.getHireDay().toString());
    }
}