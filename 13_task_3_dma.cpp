#include "13_task_3_dma.h"

abstractDMA::abstractDMA(const char * l, int r)
{
	label = new char [strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

abstractDMA::abstractDMA(const abstractDMA & rs)
{
	label = new char [strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

abstractDMA::~abstractDMA()
{
	delete [] label;
}

abstractDMA & abstractDMA::operator=(const abstractDMA & rs)
{
	if (this == &rs)
	{
		return *this;
	}
	delete [] label;
	label = new char [strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

void abstractDMA::View () const
{
	cout << "Label: " << label << endl
		 << "Rating: " << rating << endl;
}

void baseDMA::View () const
{
	abstractDMA::View();
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) : abstractDMA(l, r)
{
	strcpy(color, c);
}

lacksDMA::lacksDMA(const char * c, const abstractDMA & rs) : abstractDMA(rs)
{
	strcpy(color, c);
}

void lacksDMA::View () const
{
	abstractDMA::View();
	cout << "Color: " << color << endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r) : abstractDMA(l, r)
{
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const abstractDMA & rs) : abstractDMA(rs)
{
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : abstractDMA(hs)
{
	style = new char [strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	if (this == &rs)
	{
		return *this;
	}
	delete [] style;
	abstractDMA::operator=(rs);
	style = new char [strlen(rs.style) + 1];
	strcpy(style, rs.style);
	return *this;
}

void hasDMA::View () const
{
	abstractDMA::View();
	cout << "Style: " << style << endl;
}