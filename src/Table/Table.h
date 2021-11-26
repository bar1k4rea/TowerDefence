/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TABLE_H
#define TOWER_DEFENCE_TABLE_H

#include <iostream>

namespace TowerDefence {

    // Struct Pair
    template<typename T1, typename T2>
    struct Pair {
        T1 key;
        T2 data;
    };

    // Class Table
    template<typename T1, typename T2>
    class Table {
    private:
        static const int BLOCK;
        int m_counter;
        Pair<T1, T2> *m_array;
    public:
        Table();

        Table(int counter, const Pair<T1, T2> *array);

        ~Table();

        void push(Pair<T1, T2> pair);

        T2 find(T1 key);

        T2 operator[](T1 key);

        [[nodiscard]] int getCounter() const;
    };

    // Empty constructor for Table.
    template<typename T1, typename T2>
    Table<T1, T2>::Table() : m_counter(0), m_array(nullptr) {
        std::cout << "Empty Constructor for Table: " << this << std::endl;
    }

    // First constructor for Table.
    template<typename T1, typename T2>
    Table<T1, T2>::Table(int counter, const Pair<T1, T2> *array) : m_counter(counter) {
        if (!m_counter)
            m_array = nullptr;
        else {
            m_array = new int[BLOCK * ((m_counter - 1) / BLOCK + 1)];
            for (int i = 0; i < m_counter; i++)
                m_array[i] = array[i];
        }
        std::cout << "First Constructor for Table: " << this << std::endl;
    }

    // Destructor for Table.
    template<typename T1, typename T2>
    Table<T1, T2>::~Table() {
        m_counter = 0;
        delete [] m_array;
    }

    // Add Pair.
    template<typename T1, typename T2>
    void Table<T1, T2>::push(Pair<T1, T2> pair) {
        if (!(m_counter % BLOCK)) {
            Pair<T1, T2> *array;
            array = new Pair<T1, T2>[BLOCK * (m_counter / BLOCK + 1)];
            for (int i = 0; i < m_counter; i++)
                array[i] = m_array[i];
            delete[] m_array;
            array[m_counter++] = pair;
            m_array = array;
        } else
            m_array[m_counter++] = pair;
    }

    // Find data in Pair.
    template<typename T1, typename T2>
    T2 Table<T1, T2>::find(T1 key) {
        for (int i = 0; i < m_counter; i++)
            if (key == m_array[i].key)
                return m_array[i].data;
    }

    // Indexing operator.
    template<typename T1, typename T2>
    T2 Table<T1, T2>::operator[](T1 key) {
        return find(key);
    }

    // Getter for m_counter.
    template<typename T1, class T2>
    int Table<T1, T2>::getCounter() const {
        return m_counter;
    }

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TABLE_H */