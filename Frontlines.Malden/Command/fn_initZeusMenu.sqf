/*
	File: fn_initZeusMenu.sqf
	Author: Dom
	Description: Opens and populates the zeus menu
*/

private _display = createDialog ["DT_zeusMenu",true];
private _sectorListbox = _display displayCtrl 1500;
{
	private _index = _sectorListbox lbAdd (_x getVariable "DT_sectorName");
	_sectorListbox lbSetData [_index,netId _x];

	private _colour = [0.5,0,0,1];
	if (_x getVariable ["DT_sectorOwned",false]) then {
		_colour = [0,0.3,0.6,1];
	} else {
		if (_x in DT_activeSectors) then {
			_colour = [0.85,0.4,0,1];
		};
	};
	_sectorListbox lbSetColor [_index,_colour];
} forEach DT_allSectors;
lbSort _sectorListbox;

private _fobListbox = _display displayCtrl 1501;
{
	private _index = _fobListbox lbAdd (_x getVariable "DT_fobName");
	_fobListbox lbSetData [_index,netId _x];
} forEach DT_allFOBs;
lbSort _fobListbox;

_sectorListbox lbSetCurSel 0;
_fobListbox lbSetCurSel 0;