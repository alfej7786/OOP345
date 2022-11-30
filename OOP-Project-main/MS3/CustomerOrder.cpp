// Name: Alfej Savaya
// Seneca Student ID: 118823210
// Seneca email: aasavaya@myseneca.ca
// Date of completion: 15-Nov-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

using namespace std;
namespace sdds
{
    size_t CustomerOrder::m_widthField{0};

    CustomerOrder::CustomerOrder() { ; }

    CustomerOrder::CustomerOrder(const string& str) {
		size_t next_pos = 0;
		bool more = true;
		Utilities ut;

		m_name = ut.extractToken(str, next_pos, more);
		m_product = ut.extractToken(str, next_pos, more);
		vector<Item*> tempVec;
		Item* tempItem;
		while (more) 
		{
			tempItem = new Item(ut.extractToken(str, next_pos, more));
			tempVec.push_back(tempItem);
		}
		m_cntItem = tempVec.size();
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++)m_lstItem[i] = tempVec[i];

		CustomerOrder::m_widthField = CustomerOrder::m_widthField > ut.getFieldWidth() ? CustomerOrder::m_widthField : ut.getFieldWidth();
	}

    CustomerOrder::CustomerOrder(const CustomerOrder& str) {
		throw -1;
	}


    CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
        *this = move(order);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
		if (this != &order) {
			for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
			delete[] m_lstItem;
			m_name = order.m_name;
			m_product = order.m_product;
			m_cntItem = order.m_cntItem;
			m_lstItem = order.m_lstItem;
			order.m_lstItem = nullptr;
			order.m_cntItem = 0;
		}
		return *this;
	}

    CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

    bool CustomerOrder::isOrderFilled() const {
		bool result = true;
		for (size_t i = 0; i < m_cntItem && result; i++) 
		{
			if (m_lstItem[i]->m_isFilled == false) result = false;
		}
		return result;
	}


    bool CustomerOrder::isItemFilled(const string& itemName) const {
		bool result = true;
		for (size_t i = 0; i < m_cntItem && result; i++) 
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false) result = false;
		}
		return result;
	}


    void CustomerOrder::fillItem(Station& station, ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) 
		{
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) 
			{
				if (station.getQuantity() >= 1) 
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" 
					<< m_lstItem[i]->m_itemName << "]" << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product 
					<< " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}


    void CustomerOrder::display(ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[";
			os.width(6);
			os.fill('0');
			os.setf(ios::right);
			os << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os.fill(' ');
			os.width(m_widthField + 2);
			os.unsetf(ios::right);
			os.setf(ios::left);
			os << m_lstItem[i]->m_itemName;
			os << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" << endl : os << "TO BE FILLED" << endl;
		}
    }
}