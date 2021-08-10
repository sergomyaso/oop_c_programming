#include <iostream>
#include <unordered_map>
#include <vector>

namespace trit {

	enum Trit { Unknown, True, False };

	namespace constants {
		const size_t SIZE_UINT = sizeof(unsigned int);
		const size_t BIT_IN_BYTE = 8; // 8 bit in one byte
	}

	unsigned int getBits(const size_t countBits);
	size_t getOffset(const size_t index);
	Trit getValueByRefernce(unsigned int* reference, size_t index);

	class TritSet {

	private:
		class TritReference {
		private:
			unsigned int* reference;
			size_t index;
			Trit value;
			TritSet* set;
		public:
			TritReference(unsigned int* reference, size_t index, TritSet* set);
			TritReference(const TritReference& obj);
			TritReference& operator=(const Trit trit);
			TritReference& operator=(const TritReference& obj);
			bool operator==(const Trit trit_arg)const;
			bool operator==(const TritSet::TritReference& obj)const;
			bool operator!=(const Trit trit_arg)const;
			bool operator!=(const TritSet::TritReference& obj)const;
			TritReference operator&(const Trit trit_arg)const;
			TritReference operator&(const TritReference& obj)const;
			TritReference operator&=(const Trit trit_arg)const;
			TritReference operator&=(const TritReference& obj)const;
			TritReference operator|(const Trit trit_arg)const;
			TritReference operator|(const TritReference& obj)const;
			TritReference operator|=(const Trit trit_arg)const;
			TritReference operator|=(const TritReference& obj)const;
			TritReference& operator~();
			Trit getValue()const;
		};
	public:
		static const size_t CAPCITY_TRIT = 2;		
	private:
		int size;
		void addMemory(const size_t count);
		std::vector <unsigned int> tritContainer;
	public:
		TritSet(int size);
		TritReference operator[](size_t index);
		Trit operator[](size_t index)const;
		TritSet operator&(TritSet& set)const;
		void operator&=(TritSet& set);
		TritSet operator|(TritSet& set)const;
		void operator|=(TritSet& set);
		void operator~();
		size_t capacity()const;
		size_t cardinality(const Trit value)const;
		std::unordered_map< Trit, int, std::hash<int> > cardinality()const;
		void trim(size_t lastIndex);
		size_t length()const;
		void shrink();
	};

	namespace constants {
		const size_t INDEX_COUNT = SIZE_UINT * BIT_IN_BYTE / TritSet::CAPCITY_TRIT;
	}
}
