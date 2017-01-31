//
// Created by voyevoda on 31/01/17.
//

#ifndef CMAKE_BUILD_DEBUG_PARSER_H
#define CMAKE_BUILD_DEBUG_PARSER_H

#include <string>
#include <vector>

 namespace nts
 {
 enum class ASTNodeType : int
 {
 DEFAULT = -1,
 NEWLINE = 0,
 SECTION = 1,
 COMPONENT = 2,
 LINK = 3,
 LINK_END = 4,
 STRING = 5
 };

 typedef struct s_ast_node
 {
 s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) {}
 std::string	        lexeme;
 ASTNodeType		type;
 std::string		value;
 std::vector<struct s_ast_node*>	*children;
 }		t_ast_node;

 class IParser
 {
 public:
 virtual void feed(std::string const& input) = 0;
 virtual void parseTree(t_ast_node& root) = 0;
 virtual t_ast_node *createTree() = 0;
 virtual ~IParser();
 };
 }

#endif CMAKE_BUILD_DEBUG_PARSER_H



#endif //CMAKE_BUILD_DEBUG_PARSER_H
