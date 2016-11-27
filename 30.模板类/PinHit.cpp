#include "PinHit.h"
//Be sure to check that pins are between 0000 and 9999
PinHit::PinHit() :m_pin(-1), m_hits(0) {
	//m_pin = -1;
	//m_hits = 0;
}

PinHit::PinHit(int key, int value) : m_pin(key), m_hits(value) {

}

void PinHit::SetKey(int pin) {
	if (pin >= 0 && pin <= 9999)
		this->m_pin = pin;
	else{
		this->m_pin = -1;
	}
}

int PinHit::GetKey() const {
	return m_pin;
}

int PinHit::GetValue() const {
	return m_hits;
}

void PinHit::IncrementHits() {
	++m_hits;
}

//Compares the Value (hits) of this PinHit. Returns 0 if they are the same, negative if this is less than other or positive if this is greater than other.Note, this does not compare the pin numbers in any way.
int PinHit::CompareTo(const PinHit& other) const {
	return other.m_hits == this->m_hits ? 0 : \
		(other.m_hits < this->m_hits ? -1 : 1);
}

bool PinHit::operator==(const PinHit& other) {
	return other.m_pin == m_pin ? true : false;
}


bool PinHit::operator<(const PinHit& other) {
	return  m_hits < other.m_hits ? true : false;
}

bool PinHit::operator>(const PinHit& other) {
	return m_hits > other.m_hits ? true : false;
}
