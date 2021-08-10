#include "tritSet.h"

namespace trit {

	unsigned int getBits(const size_t countBits){
		unsigned int result = 0;
		for (int power = 0; power < countBits; power++) {
			result += 1 << power;
		}
		return result;
	}

	size_t getOffset(const size_t index) {
		return (constants::SIZE_UINT * constants::BIT_IN_BYTE) - (index * TritSet::CAPCITY_TRIT + TritSet::CAPCITY_TRIT);
	}

	Trit getValueByRefernce(unsigned int reference, size_t index) {
		size_t offset = getOffset(index);
		unsigned int mask = getBits(TritSet::CAPCITY_TRIT) << offset;
		Trit value = (Trit)((reference & mask) >> (offset));
		return value;
	}

	TritSet::TritReference::TritReference(unsigned int* reference, size_t index, TritSet* set) {
		this->set = set;
		this->reference = reference;
		if (!reference) {
			/*NULL reference, not allocated memmory*/
			this->index = index;
			this->value = Unknown;
		}
		else {
			if (index > constants::INDEX_COUNT - 1) {
				index = index % constants::INDEX_COUNT;
			}
			this->index = index;
			this->value = getValueByRefernce(*this->reference, index);
		}
	}

	TritSet::TritReference::TritReference(const TritReference& obj) {
		this->set = obj.set;
		this->reference = obj.reference;
		this->index = obj.index;
		this->value = obj.value;
	}

	TritSet::TritReference& TritSet::TritReference::operator=(const Trit trit_arg) {
		if (!this->reference && trit_arg != Unknown) {
			//In this case we add memory to conatiner for new not Unknown trit
			size_t sizeToAdd = (this->index / constants::INDEX_COUNT + 1) - this->set->tritContainer.size();
			this->set->size = (int)index + 1;
			set->addMemory(sizeToAdd);
			this->reference = &this->set->tritContainer[this->index / constants::INDEX_COUNT];
			this->index = index % constants::INDEX_COUNT;
		}

		if (this->reference) {
			//Change trit value by reference using masks and bit offset
			if (index >= this->set->size)
				this->set->size = (int)index + 1;
			size_t offset = getOffset(this->index);
			unsigned int residualPart = getBits(offset) & (*this->reference);
			*this->reference >>= offset + TritSet::CAPCITY_TRIT;
			*this->reference <<= TritSet::CAPCITY_TRIT;
			*this->reference =  ((*this->reference + trit_arg) << offset) + residualPart;
			this->value = trit_arg;
			return *this;
		}
	}

	TritSet::TritReference& TritSet::TritReference::operator=(const TritSet::TritReference& obj) {
		*this = obj.value;
		return *this;
	}

	Trit TritSet::TritReference::getValue()const {
		return this->value;
	}


	bool TritSet::TritReference::operator==(const Trit trit_arg)const {
		if (this->value == trit_arg) {
			return true;
		}
		return false;
	}
	bool TritSet::TritReference::operator==(const TritSet::TritReference& obj)const {
		return *this == obj.value;
	}

	TritSet::TritReference TritSet::TritReference::operator&(const Trit trit_arg)const {
		TritReference result = *this;
		if (this->value == False || trit_arg == False) {
			result = False;
			return result;
		}
		if (this->value == Unknown || trit_arg == Unknown) {
			result = Unknown;
			return result;
		}
		result = True;
		return result;
	}

	TritSet::TritReference TritSet::TritReference::operator&(const TritSet::TritReference& obj)const {
		return *this & obj.value;
	}

	TritSet::TritReference TritSet::TritReference::operator&=(const Trit trit_arg)const {
		return *this & trit_arg;
	}

	TritSet::TritReference TritSet::TritReference::operator&=(const TritSet::TritReference& obj)const {
		return *this & obj;
	}

	TritSet::TritReference TritSet::TritReference::operator|(const Trit trit_arg)const {
		TritReference result = *this;
		if (this->value == True || trit_arg == True) {
			result = True;
			return result;
		}
		if (this->value == Unknown || trit_arg == Unknown) {
			result = Unknown;
			return result;
		}
		result = False;
		return result;
	}

	TritSet::TritReference TritSet::TritReference::operator|(const TritSet::TritReference& obj)const {
		return *this | obj.value;
	}

	TritSet::TritReference TritSet::TritReference::operator|=(const Trit trit_arg)const {
		return *this | trit_arg;
	}

	TritSet::TritReference TritSet::TritReference::operator|=(const TritSet::TritReference& obj)const {
		return *this | obj;
	}

	bool TritSet::TritReference::operator!=(const Trit trit_arg)const {
		if (*this == trit_arg)
			return false;
		return true;
	}

	bool TritSet::TritReference::operator!=(const TritSet::TritReference& obj)const {
		return *this != obj.value;
	}

	TritSet::TritReference& TritSet::TritReference::operator~() {
		if (this->value == True) {
			*this = False;
			return *this;
		}
		if (this->value == False) {
			*this = True;
			return *this;
		}
		return *this;
	}

	TritSet::TritSet(int size) {
		this->size = size;
		for (size_t i = 0; i <= this->size / constants::INDEX_COUNT + 1; i++) {
			this->tritContainer.push_back(0);
		}
	}

	void TritSet::addMemory(const size_t count) {
		for (size_t i = 0; i < count; i++) {
			this->tritContainer.push_back(0);
		}
	}

	TritSet::TritReference TritSet::operator[](size_t index) {
		if (index / constants::INDEX_COUNT >= this->capacity()) //When memmory not allocated for this index
			return TritReference(NULL, index, this);
		return TritReference(&(this->tritContainer[index / constants::INDEX_COUNT]), index, this);
	}

	Trit TritSet::operator[](size_t index)const {
		if (index / constants::INDEX_COUNT >= this->capacity())
			return Unknown;

		size_t currentIntIndex = index;
		if (index > constants::INDEX_COUNT - 1) {
			index = index % constants::INDEX_COUNT;
		}
		Trit value = getValueByRefernce(this->tritContainer[currentIntIndex / constants::INDEX_COUNT], index);
		return value;
	}

	TritSet TritSet::operator&(TritSet& set)const {
		auto sizeSet = this->size;
		if (sizeSet < set.size)
			sizeSet = set.size;

		TritSet result(sizeSet);
		for (size_t i = 0; i < sizeSet; i++){
			result[i] = set[i] & (*this)[i];
		}
		return result;
	}

	void TritSet::operator&=(TritSet& set) {
		*this = *this & set;;
	}

	TritSet TritSet::operator|(TritSet& set)const {
		auto sizeSet = this->size;
		if (sizeSet < set.size)
			sizeSet = set.size;

		TritSet result(sizeSet);
		for (size_t i = 0; i < sizeSet; i++) {
			result[i] =set[i] | (*this)[i];
		}
		return result;
	}

	void TritSet::operator|=(TritSet& set) {
		*this = *this | set;
	}

	void TritSet::operator~() {
		for (size_t i = 0; i < this->size; i++) {
			~(*this)[i];
		}
	}

	size_t TritSet::capacity()const {
		return this->tritContainer.size();
	}

	size_t TritSet::cardinality(const Trit value)const {
		size_t countTrits = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			if ((*this)[i] == value)
				countTrits++;
		}
		return countTrits;
	}

	std::unordered_map< Trit, int, std::hash<int> > TritSet::cardinality()const {
		std::unordered_map< Trit, int, std::hash<int> > result;
		result[False] = (int)this->cardinality(False);
		result[True] = (int)this->cardinality(True);
		result[Unknown] = (int)this->cardinality(Unknown);
		return result;
	}

	void TritSet::trim(size_t lastIndex) {
		if (lastIndex <= this->size) {
			size_t indexLastInt = lastIndex / constants::INDEX_COUNT + 1;
			//Free all UINT after current UINT
			for (size_t i = indexLastInt; i < this->capacity(); i++) {
				this->tritContainer.pop_back();
			}
			if (this->tritContainer.size() == 0)
				return;
			if (lastIndex % constants::INDEX_COUNT == 1) {
				//In case, when current trit in begin of UINT
				this->tritContainer.pop_back();
			}
			else {
				//Make Unknown all trits after last index trit in current UINT
				size_t currentIndex = (lastIndex % constants::INDEX_COUNT);
				unsigned int mask = getBits(currentIndex * TritSet::CAPCITY_TRIT) << (constants::INDEX_COUNT - currentIndex) * TritSet::CAPCITY_TRIT;
				this->tritContainer[lastIndex / constants::INDEX_COUNT] &= mask;
			}
			this->size -= (int)(this->size - lastIndex);
		}
	}

	size_t TritSet::length()const {
		for (int i = this->size; i >= 0; i--) {
			if ((*this)[i] != Unknown)
				return i + 1;
		}
		return 0;
	}

	void TritSet::shrink() {
		size_t currentIndex = this->length() - 1;
		(*this)[currentIndex] = Unknown;
		currentIndex = this->length();
		this->trim(currentIndex);
		
	}

}
