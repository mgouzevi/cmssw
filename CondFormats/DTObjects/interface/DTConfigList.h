#ifndef DTConfigList_H
#define DTConfigList_H
/** \class DTConfigList
 *
 *  Description:
 *       Class to hold configuration identifier for chambers
 *
 *  $Date: 2007/11/24 12:29:10 $
 *  $Revision: 1.1.4.2 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------
class DTConfigToken {

 public:

  DTConfigToken();
  ~DTConfigToken();

  int id;
  std::string ref;

};


class DTConfigList {

 public:

  /** Constructor
   */
  DTConfigList();
  DTConfigList( const std::string& version );

  /** Destructor
   */
  virtual ~DTConfigList();

  /** Operations
   */
  /// get content
  int get( int id,
           DTConfigToken& token ) const;

  /// access version
  const
  std::string& version() const;
  std::string& version();

  /// reset content
  void clear();

  int set( int id, const DTConfigToken& token );
  /// Access methods to data
  typedef std::vector< std::pair<int,DTConfigToken> >::const_iterator
                                                       const_iterator;
  const_iterator begin() const;
  const_iterator end() const;

 private:

  DTConfigList( const DTConfigList& x );
  const DTConfigList& operator=( const DTConfigList& x );

  std::string dataVersion;
  std::vector< std::pair<int,DTConfigToken> > dataList;

  /// read and store full content
  void cacheMap() const;
  std::string mapName() const;

};


#endif // DTConfigList_H

