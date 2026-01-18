#include "graffit.c"

/**
 * Here's some basic testing code. It's primarily intended to give you an idea of
 * how these functions are used.
 *
 * As always, you should add more tests.
 */
int main() {
    // Users & Brands
    User* angela = create_user("Angela");
    User* brian = create_user("Brian");
    // Expect to see Angela with her friend Brian
    add_friend(angela,brian);
    // Expect to see Brian with his friend Angela
    //print_user_data(angela);
    //print_user_data(brian);
    //print_user_data(robert);
    int angela_and_brian = get_degrees_of_connection(brian, angela);
    // Expect 1
    populate_brand_matrix("brands.txt");
    printf("Connections between Brian and Angela: %d\n", angela_and_brian);
    follow_brand(angela, "brandonRufino");
    // Angela should now follow brandonRufino.
	  // Brandon was a TA for this course and there's a pun too good to give up.
    //print_user_data(angela);
    //print_brand_data("brandZero"); // Similar to brandonRufino
    //print_brand_data("brandonRufino"); // Similar to brandZero
    //print_brand_data("brandTwo"); // Not similar to anything
    connect_similar_brands("brandZero", "brandTwo");
    print_brand_data("brandZero"); // Similar to brandonRufino and brandTwo
    print_brand_data("brandonRufino"); // Similar to brandZero
    print_brand_data("brandTwo"); // Simlar to brandZero
	User* will = create_user("Will");
  add_friend(angela, will);
	//print_user_data(will); // Expect to see Will with his friend Angela
	//int mutuals_brian_will = get_mutual_friends(brian, will);
	// Expect 1
  //printf("Brian and Will have %d mutual friends\n",mutuals_brian_will);
    // Last Part
    // This should return Will
    User* brianSuggested = get_suggested_friend(brian);
    print_user_data(brianSuggested); // We should see Will here again
    User* mustafa = create_user("Mustafa");
    add_friend(angela, mustafa);
    // print_user_data(mustafa);
    // print_user_data(angela);
    // print_user_data(brian);
    //print_user_data(will);
    add_suggested_friends(mustafa, 2);
    // Expect to see Mustafa with friends Angela, Brian, and Will
    print_user_data(mustafa);
    follow_brand(will, "brandTwo");
    follow_brand(mustafa, "brandZero");
    follow_suggested_brands(mustafa, 0);
    print_user_data(mustafa); // Mustafa should now also follow brandTwo
    printf("\nDefault testing complete good job :)\n");
    User *josh = create_user("Josh");
    User *tom = create_user("Tom");
    print_user_data(josh);
    printf ("%d,",get_mutual_friends(angela, josh));
    printf ("%d",get_degrees_of_connection(tom, josh));
    remove_friend(angela,brian);
    remove_friend(angela,will);
    remove_friend(angela,mustafa);
    remove_friend(mustafa,brian);
    remove_friend(mustafa,will);
    printf("\n");

    add_friend(angela,brian);
    add_friend(brian,josh);
    add_friend(josh,mustafa);
    add_friend(mustafa,tom);
    add_friend(tom,will);

    print_user_data(angela);
    print_user_data(brian);
    print_user_data(will);
    print_user_data(mustafa);
    print_user_data(josh);
    print_user_data(tom);

    printf("%d",get_degrees_of_connection(angela,tom));
    add_suggested_friends(angela, 6);
}
