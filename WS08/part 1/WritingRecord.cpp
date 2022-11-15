#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0u; i < emp.size(); i++) {
			for (size_t j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* pro = new EmployeeWage(emp[i].id, sal[j].salary);
					pro->rangeValidator();
					activeEmp += pro;
					delete pro;
				}
			}
		}
		
		return activeEmp;
	}
}