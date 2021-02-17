#pragma once
#include <cstdint>

class CString
{
public:
					CString();
					CString( const char* c );
					CString( const CString& c );

	char &			operator[]( const int i );
	char			operator[]( const int i ) const;

	char *			Base();
	char const *	Base() const;

	char *			Begin();
	char const *	Begin() const;
	char *			End();
	char const *	End() const;

	void			Resize( const uint32_t s, const char& t = char() );

	char &			Front();
	const char &	Front() const;
	char &			Back();
	const char &	Back() const;

	void			PushBack( char t );
	void			PopBack();

	void			Reserve( const uint32_t s );

	uint32_t		Size() const;
	uint32_t		Capacity() const;

private:
	char*			e;

	void			Realloc( const uint32_t s );

	uint32_t		length;
	uint32_t		capacity;
};
