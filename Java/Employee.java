// package packegesMine.mine.account;
// package com.LeX.account;
package work.account;
import java.time.LocalDate;
import java.util.Objects;

// public class??/
public class Employee{

    private String name;
    private double salary;
    private LocalDate hireDay;

    public Employee(String _name, double _salary, int year, int month, int day){
        name = _name;
        salary = _salary;
        hireDay = LocalDate.of(year, month, day);
    }
    
    //methods
    public String getName(){
        return name;
    }
    /**
     * @param There is no param
     * @return Return a salary value
     */
    public double getSalary(){
        return salary;
    }
    public LocalDate getHireDay(){
        return hireDay;
    }
    public void raiseSalary(int percent){
        salary += salary / 100 * percent;
    }
    public void checkInfo(){
        System.out.print("Name: " + name + ", " + 
                         "Salary: " + getSalary() + ", " + 
                         "Hire day: " + hireDay.toString() + ".");
    }

    public boolean equals(Object other){
        if (this == other)
            return true;
        if (other == null)
            return false;
        if (getClass() != other.getClass())
            return false;
        Employee otherEmployee = (Employee) other;
        return Objects.equals(name, otherEmployee.name)
                && salary == otherEmployee.salary
                && Objects.equals(hireDay, otherEmployee.hireDay);
    }
    public int hashCode(){
        return Objects.hash(name, salary, hireDay);
    }
    public String toString(){
        return getClass().getName() + "[name="
                + name + ",salary=" + salary + ",hireDay=" + hireDay + "]";
    }

    public static void main(String[] args){
        var checkEmp = new Employee("Jack Salivan", 100000, 1923, 12, 23);
        checkEmp.checkInfo(); System.out.println();
        checkEmp.raiseSalary(10);
        checkEmp.checkInfo(); System.out.println();
    }
    
}