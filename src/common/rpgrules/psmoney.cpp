
/*
 * psmoney.cpp by Anders Reggestad <andersr@pvv.org>
 *
 * Copyright (C) 2001 Atomic Blue (info@planeshift.it, http://www.atomicblue.org) 
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation (version 2 of the License)
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *
 */

#include <psconfig.h>

#include "psmoney.h"
#include "util/log.h"


psMoney::psMoney()
    :circles(0), octas(0), hexas(0), trias(0)
{
}

psMoney::psMoney(int trias)
    :circles(0), octas(0), hexas(0), trias(trias)
{
}

psMoney::psMoney(int circles, int octas, int hexas, int trias)
    :circles(circles), octas(octas), hexas(hexas), trias(trias)
{
}

psMoney::psMoney(const char * moneyString)
    :circles(0), octas(0), hexas(0), trias(0)
{
    Set(moneyString);
}

void psMoney::Set(const char * moneyString)
{
    // This constructor gets called from a message cracker, we cannot presume moneyString will be valid
    if (moneyString==NULL)
        return;

    if (sscanf(moneyString,"%d,%d,%d,%d",&circles,&octas,&hexas,&trias) != 4)
    {
        circles = octas = hexas = 0;
        if (sscanf(moneyString,"%d",&trias) != 1)
        {
            trias = 0;
        }
    }
}

void psMoney::Set( int type, int value )
{
    switch( type )
    {
        case MONEY_TRIAS:   SetTrias( value ); break;
        case MONEY_HEXAS:   SetHexas( value ); break;
        case MONEY_OCTAS:   SetOctas( value ); break;
        case MONEY_CIRCLES: SetCircles( value ); break;
    }
}

void psMoney::Set(int circles, int octas, int hexas, int trias)
{
    this->circles  =  circles;
    this->octas    =  octas;
    this->hexas    =  hexas;
    this->trias    =  trias;
}

int psMoney::GetTotal() const
{
    int64 total = circles*CIRCLES_VALUE_TRIAS + octas*OCTAS_VALUE_TRIAS
        + hexas*HEXAS_VALUE_TRIAS + trias;
    if(total > INT_MAX)
	total = INT_MAX;
    return (int)total;
}

csString psMoney::ToString() const
{ 
    return csString().Format("%d,%d,%d,%d",circles,octas,hexas,trias);
}

csString psMoney::ToUserString() const
{
    if(!trias && !hexas && !octas && !circles)
        return csString("0 Trias");

    csString c,o,h,t;

    if (circles)
        c.Format("%d Circles",circles);
    if (octas)
        o.Format("%d Octas",octas);
    if (hexas)
        h.Format("%d Hexas",hexas);
    if (trias)
        t.Format("%d Trias",trias);

    csString temp;
    if (c.Length())
        temp.Append(c);

    if (temp.Length() && o.Length() && !h.Length() && !t.Length())
    {
        temp.Append(" and ");
        temp.Append(o);
        return temp;
    }
    if (temp.Length() && o.Length())
    {
        temp.Append(", ");
        temp.Append(o);
    }
    else if (o.Length())
        temp = o;

    if (temp.Length() && h.Length() && !t.Length())
    {
        temp.Append(" and ");
        temp.Append(h);
        return temp;
    }
    if (temp.Length() && h.Length())
    {
        temp.Append(", ");
        temp.Append(h);
    }
    else if (h.Length())
        temp = h;
    
    if (temp.Length() && t.Length())
    {
        temp.Append(" and ");
        temp.Append(t);
        return temp;
    }
    else if (t.Length())
    {
        return t;
    }
    else
    {
        return temp;
    }
}

void psMoney::Adjust( int type, int value, bool makeChange )
{
    switch( type )
    {
        case MONEY_TRIAS:   AdjustTrias(  value, makeChange ); break;
        case MONEY_HEXAS:   AdjustHexas(  value, makeChange ); break;
        case MONEY_OCTAS:   AdjustOctas(  value, makeChange ); break;
        case MONEY_CIRCLES: AdjustCircles(value, makeChange ); break;
    }
}


void psMoney::AdjustCircles( int c,bool makeChange )
{ 
	circles+= c; 
	if ( circles < 0 )
		circles = 0;
}

void psMoney::AdjustOctas( int c,bool makeChange )
{ 
	octas+= c; 
	if ( octas < 0 )
		octas = 0;
}
void psMoney::AdjustHexas( int c,bool makeChange )
{ 
    hexas+= c; 
    if ( hexas < 0 )
        hexas = 0;
}


void psMoney::AdjustTrias( int c,bool makeChange )
{ 
    trias+= c; 
    if ( trias < 0 )
        trias = 0;
}

int psMoney::Get( int type )
{
    switch( type )
    {
        case MONEY_TRIAS:   return trias;
        case MONEY_HEXAS:   return hexas;
        case MONEY_OCTAS:   return octas;
        case MONEY_CIRCLES: return circles;
    }
    return 0;
}

psMoney psMoney::Normalized() const
{
    int tot = GetTotal(); 
    int c = tot/CIRCLES_VALUE_TRIAS;
    tot = tot%CIRCLES_VALUE_TRIAS;
    int o = tot/OCTAS_VALUE_TRIAS;
    tot = tot%OCTAS_VALUE_TRIAS;
    int h = tot/HEXAS_VALUE_TRIAS;
    tot = tot%HEXAS_VALUE_TRIAS;
    int t = tot;
    return psMoney(c,o,h,t);
}


bool psMoney::operator > (const psMoney& other) const
{
    return GetTotal() > other.GetTotal();
}
psMoney psMoney::operator +=(const psMoney& other)
{
    circles += other.circles;
    octas += other.octas;
    hexas += other.hexas;
    trias += other.trias;
    return psMoney(circles, octas, hexas, trias);
}
psMoney psMoney::operator - (void) const
{
    return psMoney(-circles, -octas, -hexas, -trias);
}

psMoney psMoney::operator - (const psMoney& other) const
{
    psMoney left,taken;
    left = *this;
    
    int type = MONEY_TRIAS;
    while (taken.GetTotal() < other.GetTotal() && type <= MONEY_CIRCLES)
    {
        while (left.Get(type) && taken.GetTotal() < other.GetTotal())
        {
            taken.Adjust(type,1);
            left.Adjust(type,-1);
        }
        type++;
    }
    
    // Now we might have taken a little to much so calculate and give
    // change.
    psMoney change(0,0,0,taken.GetTotal()-other.GetTotal());

    psMoney result = left+change.Normalized();

    if (result.GetTotal() != (GetTotal()-other.GetTotal()))
    {
        Error5("Something is very wrong %d - %d = %d but calculated to be %d",
               GetTotal(),other.GetTotal(),(GetTotal()-other.GetTotal()),result.GetTotal());
        // If the calculation go wrong make sure we don't return anything wrong from this function.
        result = psMoney(0,0,0,GetTotal()-other.GetTotal()).Normalized();
    }

    //    csString str;
    //    str.AppendFmt("Money[%s](%d) - Money[%s](%d) = Money[%s](%d)",
    //                ToString().GetDataSafe(),GetTotal(),other.ToString().GetDataSafe(),other.GetTotal(),
    //                result.ToString().GetDataSafe(),result.GetTotal());
    //  Debug1(LOG_EXCHANGES, str.GetDataSafe());

    return result;
}

psMoney psMoney::operator + (const psMoney& other) const
{
    return psMoney(circles+other.circles,
                   octas+other.octas,
                   hexas+other.hexas,
                   trias+other.trias);
}

psMoney psMoney::operator * (const int mult) const
{
    return psMoney(circles*mult,octas*mult,hexas*mult,trias*mult);
}

