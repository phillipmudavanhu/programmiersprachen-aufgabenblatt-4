#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>


template <typename T>
class List;

template <typename T>
struct ListNode
{
  ListNode(): value(), prev(nullptr), next(nullptr){}
	
  ListNode(T const&currentValue, ListNode*prevNode, ListNode*nextNode)
  : value(currentValue), prev(prevNode), next(nextNode)
  {}
  T value;
  ListNode* prev;
  ListNode* next;
};



template <typename T>
struct ListConstIterator
{
  friend class List < T >;
  private :
  ListNode < T >* node = nullptr ;
};

//___________________________________________________________________________Aufgabe 4.5

template <typename T>
class ListIterator
{
  public:
    using Self = ListIterator <T>;

    using value_type = T; 
    using pointer = T*; 
    using reference = T&; 
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

	friend class List <T>;

	ListIterator(): 
		node(nullptr){}

	ListIterator(ListNode <T>*n):
		node(n) {}

	reference operator*() const
		{return node->value;}

	pointer operator->() const
		{return *node;}

	Self& operator++() 
		{
			if (node)
			    node = node->next;
			return *this;
		}

	Self& operator--() 
		{
			node = node->prev;
			return *this;
		}

	Self operator++(int) 
	{
		Self temp = *this;
		++(*this);
		return temp;
	}

	bool operator==( const Self & x) const 
		{
			return node == x.node;
		}

	bool operator!=( const Self & x) const 
		{
			return node != x.node;
		}

	Self next() const
	{
		if (node)
			return ListIterator ( node -> next );
		else
			return ListIterator (nullptr);
	}

	private:
		ListNode <T >* node = nullptr ;
	};

	template <typename T>
	List<T> reverse(List<T> a)
	{
		a.reverse();
		return a;
	};

	template <typename T>
	List<T> copy(List<T> a)
	{
		return a;
	};


//___________________________________________________________________________Aufgabe 4.12

template <typename T>
bool operator==(List<T> const& xs, List<T> const& ys)
{
    ListIterator<T> a = xs.begin();
    ListIterator<T> b = ys.begin();
    if(xs.size()!=ys.size())
    {
        return false;
    }
    else
    {
        int c = 0;
        while(c<xs.size())
        {
            if(*a != *b){
                return false;
            }
            else
            {
                a++;
                b++;
                c++;
            }
        }
        return true;
    }


}


template < typename T >
bool operator !=( List <T > const & xs , List <T > const & ys )
{
	return !(xs==ys);
}



template <typename T>
class List
{
public:
	public:
    using value_type = T;
    using pointer = T*; 
    using const_pointer = T const*;
    using reference = T&;
    using const_reference = T const&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;

	friend class ListIterator<T>;
	friend class ListConstIterator<T>;


	List():
		m_size{0},
		first_node{nullptr},
		last_node{nullptr}
		 {}
	
	List(List const& myList):
		m_size{0},
		first_node{nullptr},
		last_node{nullptr}
		
		{
			if (!myList.empty())
			{
				for (auto i = myList.begin(); i != myList.end(); ++i)
				{
					push_back(*i);
				}
			}
		}

	friend void swap(List& myList, List& newList) 
		{myList.swap(newList);}

	List(List<T>&& list):
    first_node(list.first_node),
    last_node(list.last_node),
    m_size(list.m_size)

    {
       list.first_node=nullptr;
       list.last_node=nullptr;
       list.m_size=0; 
    }


	//Destructor to clear memory
	~List()
    {
        clear();
    }
	
	
	//Checking if the Link has any Nodes or not
	bool empty () const
		{
			return size()== 0;
		}

	std::size_t size() const
		{
			return m_size;
		}


	//Adding a new Node at the front of an exsiting or new Link
	void push_front(T const& a)
	{
		if (empty())
		{
			ListNode<T>* v1 =new ListNode<T>(a, nullptr, nullptr);
			first_node= v1;
			last_node= v1;
		}

		else
		{
			ListNode<T>* v2 =new ListNode<T>(a, nullptr, first_node);
			first_node->prev = v2;
			first_node = v2;
		}
		m_size+=1;
	}

	//Inserting a new Node at the front of an exsiting or new Link
	void push_back(T const& a)
	{
		if (empty())
		{
			ListNode<T>* v1 =new ListNode<T>(a, nullptr, nullptr);
			first_node= v1;
			last_node= v1;
			
		}
		else
		{
			ListNode<T>* v3 =new ListNode<T>(a, last_node, nullptr);
			last_node->next = v3;
			last_node = v3;
		}
		m_size+=1;	
	}


	//removing a new Node at the front of an exsiting after checking if its empty
	void pop_front()
	{	
		if (empty())
		{
        	std::cout << "The List is Empty and the operation is not applicable";
		}

		if (m_size == 1)
		{
			delete first_node;
			first_node = nullptr;
	    	last_node = nullptr;
	    	m_size -= 1;
		}
		
		else
		{
			auto *n = first_node->next;

			n->prev = nullptr;
			

			delete first_node;
			
			first_node = n;

			m_size -= 1;	
		}
	}

	void pop_back()
	{	
		if (empty())
		{
        std::cout << "The List is Empty and the operation is not applicable";
		}

		if (m_size == 1)
		{
			delete first_node;
			first_node = nullptr;
	    	last_node = nullptr;
	    	m_size -= 1;
		}
		
		else
		{
	        auto *n = last_node->prev;
	        n->next = nullptr;

	        delete last_node;

	        last_node = n;
	        m_size -= 1;
    	}
    }

	void clear()
	{
		while (!empty())
	    {	
		    pop_front();
	    }           
    }


   iterator insert(iterator pos, const T& value )
   {

		ListNode<T>* v1 = new ListNode<T>(value, pos.node->prev, pos.node);
		pos.node->prev->next = v1;
		pos.node->prev = v1;
		m_size+=1;
		return ListIterator<T> (v1);
	}


	void reverse()
	{	
		for (iterator i = begin(); i != end(); --i)
		{	
			std::swap(i.node->prev, i.node->next);
		}
		std::swap(first_node, last_node);
	};
	


	T const& front() const
	{
		return first_node->value;
	}

	T const& back() const
	{
		return last_node->value;
	}

	T& front()
	{
		return first_node->value;
	}

	T& back()
	{
		return last_node->value;
	}

	iterator begin() const
	{
		return ListIterator<T>(first_node);
	}

	iterator end() const
	{
		return ListIterator<T>();
	}


private:
	std::size_t m_size = 0;
	ListNode<T>* first_node= nullptr ;
	ListNode<T>* last_node= nullptr ;
};

#endif 	//#define BUW_LIST_HPP
