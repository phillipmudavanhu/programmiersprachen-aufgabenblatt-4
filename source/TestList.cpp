#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Lists.hpp"
#include <string>
#include <vector>


//___________________________________________________________________________Aufgabe 4.0- Print Function

void print(List <int> l)
{
	if (l.empty()==true){
		std::cout << "\nThe List is empty!!"<< '\n';
	}
	else {
		for (int n : l)
		{
	    	std::cout << n << '\n';
	    }
    }
 std::cout << "\n";
}


//___________________________________________________________________________Aufgabe 4.1- Test

TEST_CASE("Test for the default List", "[modifiers]")
{	

  List <int> list;
  REQUIRE (list.size()==0);
  REQUIRE (list.empty() == true);

}


//___________________________________________________________________________Aufgabe 4.2- Test

TEST_CASE ("Test for Size and Contents of default List", "[modifiers]")
{
  List<int> myList1;
  REQUIRE (myList1.size()== 0);
  REQUIRE (myList1.empty() == true);
}


//___________________________________________________________________________Aufgabe 4.3- Test

TEST_CASE("add an element with push_front", "[modifiers]")
{	

  List<int> list ;
  list.push_front (42);
  list.push_front (0);
  list.push_front (-1);
	
  REQUIRE(42 == list.back());
  REQUIRE(-1 == list.front());

  REQUIRE (list.size()== 3);
  REQUIRE (list.empty() == false);

  std::cout << "\nAufgabe 4.3a-----------The Elements in the List after push_front: " << "\n";
  print(list);
    
}

//___________________________________________________________________________Aufgabe 4.3- Test

TEST_CASE("add an element with push_back", "[modifiers]")
{	

	List<int> list ;
	list.push_back (9);
	list.push_back (2);
	list.push_back (10);
	
	
	REQUIRE(9 == list.front());
	REQUIRE(10 == list.back());

	REQUIRE (list.size()== 3);
    REQUIRE (list.empty() == false);

    std::cout << "\nAufgabe 4.3b-----------The Elements in the List after push_back: " << "\n";
    print(list);

}

TEST_CASE("delete first and last element with pop_front", "[modifiers]")
{	

	List<int> list;
	list.push_back (100);
	list.push_back (200);
	list.push_back (300);
	list.push_back (400);
	list.push_back (500);

	
	list.pop_front();//deleting (100);
	list.pop_back();//deleting (500);

	
	REQUIRE(200 == list.front());
	REQUIRE(400 == list.back());

	REQUIRE (list.size()== 3);
    REQUIRE (list.empty() == false);

	list.pop_front(); //deleting (200);

	std::cout << "\nAufgabe 4.3c-----------The Elements in the List after pop_front and back: " << "\n";
    print(list);
}

//___________________________________________________________________________Aufgabe 4.4- Test

TEST_CASE("should be empty after clearing", "[modifiers]")
{	

  List<int> list;
  list.push_back (1);
  list.push_back (2);
  list.push_back (3);
  list.push_back (4);
  list.clear();
  REQUIRE(list.empty());

  std::cout << "\nAufgabe 4.4-----------Should be empty after clearing the List using Destructor: " << "\n";
  print(list);
}

//___________________________________________________________________________Aufgabe 4.5- Test

TEST_CASE (" should be an empty range after default construction ","[iterators]")
{
	List <int > list ;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE (b == e);
}

TEST_CASE (" provide acces to the first element with begin ", "[iterators ]")
{
	List<int> list ;
	list.push_front (42);
	REQUIRE (42 == *list.begin());
}


TEST_CASE ("compare two lists", "[operators]")
{
	List<int> a;
	List<int> b;

	a.push_back (10);
	a.push_back (20);
	a.push_back (30);
	a.push_back (40);

	b.push_back (10);
	b.push_back (20);
	b.push_back (30);
	b.push_back (40);
	
	REQUIRE(a == b);

	std::cout << "\nAufgabe 4.6-----------compare two lists that are equal: " << "\n";
	std::cout << "\nlists: A " << "\n";
  	print(a);

  	std::cout << "\nlists:B " << "\n";
  	print(b);

	a.pop_front();
	REQUIRE((a == b) == false);

	std::cout << "\nLists  after pop_front-----------compare two lists that are not equal: " << "\n";
	std::cout << "\nlists: A " << "\n";
  	print(a);

  	std::cout << "\nlists:B " << "\n";
  	print(b);

}

TEST_CASE ("compare two lists of different size", "[operators]")
{
	List<int> l1;
	List<int> l2;
	l1.push_back (1);
	
	l2.push_back (1);
	l2.push_back (2);
	
	
	REQUIRE(l1 != l2);


	std::cout << "\nLists  after push_back-----------are not equal two lists: " << "\n";
	std::cout << "\nlists: A " << "\n";
  	print(l1);

  	std::cout << "\nlists:B " << "\n";
  	print(l2);
}



TEST_CASE ("Comparing two lists with different ends", "[operators]")
{
	List<int> list;
	List<int> list2;

	list.push_back (10);
	list.push_back (20);
	list.push_back (30);
	list.push_back (40);

	list2.push_back (10);
	list2.push_back (20);
	list2.push_back (30);
	list2.push_back (400);
	
	REQUIRE((list == list2) == false);

	std::cout << "\nComparing two lists with different ends-----------are not equal two lists: " << "\n";
	std::cout << "\nlists: A " << "\n";
  	print(list);

  	std::cout << "\nlists:B " << "\n";
  	print(list2);

}


TEST_CASE ("Comparing two lists with different ends with !=", "[operators]")
{
	List<int> list;
	List<int> list2;
	list.push_back (10);
	list.push_back (20);
	list.push_back (30);
	list.push_back (40);

	list2.push_back (10);
	list2.push_back (20);
	list2.push_back (30);
	list2.push_back (400);
	
	REQUIRE((list != list2) == true);

	std::cout << "\nComparing two lists with different ends with != are not equal two lists: " << "\n";
	std::cout << "\nlists: A " << "\n";
  	print(list);

  	std::cout << "\nlists:B " << "\n";
  	print(list2);

}


//___________________________________________________________________________Aufgabe 4.8- Test

TEST_CASE ( " copy constructor " , "[constructor]" )
{
	List<int> list ;
	list.push_front (1);
	list.push_front (2);
	list.push_front (3);
	list.push_front (4);
	List<int> list2 {list};
	REQUIRE (list == list2);
}

TEST_CASE ("Copying a Completely new List", "[operators]")
{
	List<int> list;
	
	list.push_back (1);
	list.push_back (2);
	list.push_back (3);
	list.push_back (6);
	
	List<int> newList(list);

	for (auto i = list.begin(); i != list.end(); ++i)
	{
		std::cout << "Old List: " << *i << "\n";
	}

	std::cout << "\n";

	for (auto i = newList.begin(); i != newList.end(); ++i)
	{
		std::cout << "New Copied List: "<< *i << "\n";
	}
	std::cout << "\n";
	
	REQUIRE(list == newList);

}


TEST_CASE ( " copy constructor: empty list" , "[constructor]" )
{
	List<int> list;
	List<int> list2 {list};
	REQUIRE (list == list2);
}



//___________________________________________________________________________Aufgabe 4.9- Test

TEST_CASE ( "insert a new number into the list" , "[iterators]" )
{	
	List<int> list;
	
	list.push_back (10);
	list.push_back (20);
	list.push_back (30);
	list.push_back (40);

	std::cout << "\ninsert a new number into the list: " << "\n";
	std::cout << "\nlists before insert " << "\n";
  	print(list);
	std::cout << "\nlists after inserting 2000 " << "\n";
  	
	list.insert(++list.begin(), 2000);


	for (auto i = list.begin(); i != list.end(); ++i)
	{	
		std::cout << *i << "\n";
	}

	REQUIRE(5 == list.size());

	std::cout << "\n";
}

//___________________________________________________________________________Aufgabe 4.10- Test

TEST_CASE ( "self reversing list" , " [member] " )
{
	List<int> list;
	
	list.push_back (100);
	list.push_back (90);
	list.push_back (80);
	list.push_back (70);

	std::cout << "\ninsert a new number into the list: " << "\n";
	std::cout << "\nlists before self reverse " << "\n";
	print(list);

	list.reverse();

	std::cout << "\nlists after reverse " << "\n";

	for (auto i = list.begin(); i != list.end(); ++i)
	{	
		std::cout << *i << "\n";
	}

	REQUIRE(4 == list.size());

	std::cout << "\n";
}




TEST_CASE ( "function: reverse" , "[iterators]" )
{	
	List<int> list;
	
	list.push_back (5);
	list.push_back (4);
	list.push_back (3);
	list.push_back (2);

	auto a = reverse(list);

	for (auto i = a.begin(); i != a.end(); ++i)
	{	
		std::cout << *i << "\n";
	}

	std::cout << "\n";

	REQUIRE(4 == list.size());

	std::cout << "\n";
}



//___________________________________________________________________________Aufgabe 4.11- Test

TEST_CASE ( "Copying a list into vector " , "[iterators]" )
{	
	List<int> list;
	list.push_back (1000);
	list.push_back (2000);
	list.push_back (3000);
	list.push_back (4000);
	list.push_back (5000);


	std::vector<int> my_vector(list.size());
    std::copy(list.begin(), list.end(), my_vector.begin());
	
	std::copy(my_vector.begin(), my_vector.end(),
    std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    }

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


//___________________________________________________________________________Aufgabe 4.13- Test

TEST_CASE ( "move constructor " , "[constructor]" )
{
	List<int> list ;
	list.push_front (1);
	list.push_front (2);
	list.push_front (3);
	list.push_front (4);

	std::cout << "\nmoving a list: " << "\n";
	std::cout << "\nOriginal before move " << "\n";
	print(list);

	List<int> list2 ( std :: move ( list ));

	std::cout << "\nOriginal List after moving " << "\n";
	print(list);

	std::cout << "\nNew List after moving " << "\n";
	print(list2);

	REQUIRE (0 == list.size ());
	REQUIRE ( list.empty ());
	REQUIRE (4 == list2.size ());
}



