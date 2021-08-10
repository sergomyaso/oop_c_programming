#pragma once

#include <iostream>
#include <string>

namespace workflow {
	const std::string innerTEST1 = "abababab\naba\nkrap\nkra\naba\n";
	const std::string resultTEST1 = "kra\nkrap\nkrap\nkrap\nkrapbkrapb\n";
	const std::string workflowTEST1 = "desc\n1 = replace aba krap\n2 = grep kra\n3 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n0 -> 1 -> 2 -> 3 -> 5\n";

	const std::string innerTEST2 = "god\ndog\nfog\ngof\nbib\nbib\ndof\ndof\n";
	const std::string resultTEST2 = "god\ngod\ngof\ngof\nbib\nbib\ndof\ndof\n";
	const std::string workflowTEST2 = "desc\n1 = replace dog god\n3 = replace fog gof\n2 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n0 -> 1 -> 3 -> 5\n";
	
	const std::string workflowOpenTEST1 = "desc\n1 = replace dog god\n3 = replace fog gof\n2 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n0 -> 1 -> 3 -> 5 -> 5\n";
	const std::string workflowValidTEST2 = "desc\n1 = replace dog god\n3 = replace fog gof\n2 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n1 -> 2 -> 0 -> 5\n";
	const std::string worfklowValidTEST3 = "desc\n1 = replace dog god\n3 = replace fog gof\n2 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n1 -> 2 -> 0 -> 3\n";
	const std::string worfklowValidTEST4 = "desc\n1 = replace dog god fog\n3 = replace fog gof\n2 = sort\n0 = readfile in.txt\n5 = writefile out.txt\ncsed\n0 -> 2 -> 1 -> 3 -> 5\n";

}
