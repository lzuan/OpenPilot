/**
 ******************************************************************************
 *
 * @file       ahrsstatus.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: ahrsstatus.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @brief      The UAVUObjects GCS plugin
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "ahrsstatus.h"
#include "uavobjectfield.h"

const QString AhrsStatus::NAME = QString("AhrsStatus");

/**
 * Constructor
 */
AhrsStatus::AhrsStatus(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField*> fields;
    QStringList SerialNumberElemNames;
    SerialNumberElemNames.append("0");
    SerialNumberElemNames.append("1");
    SerialNumberElemNames.append("2");
    SerialNumberElemNames.append("3");
    SerialNumberElemNames.append("4");
    SerialNumberElemNames.append("5");
    SerialNumberElemNames.append("6");
    SerialNumberElemNames.append("7");
    SerialNumberElemNames.append("8");
    SerialNumberElemNames.append("9");
    SerialNumberElemNames.append("10");
    SerialNumberElemNames.append("11");
    SerialNumberElemNames.append("12");
    SerialNumberElemNames.append("13");
    SerialNumberElemNames.append("14");
    SerialNumberElemNames.append("15");
    SerialNumberElemNames.append("16");
    SerialNumberElemNames.append("17");
    SerialNumberElemNames.append("18");
    SerialNumberElemNames.append("19");
    SerialNumberElemNames.append("20");
    SerialNumberElemNames.append("21");
    SerialNumberElemNames.append("22");
    SerialNumberElemNames.append("23");
    SerialNumberElemNames.append("24");
    fields.append( new UAVObjectField(QString("SerialNumber"), QString("n/a"), UAVObjectField::UINT8, SerialNumberElemNames, QStringList()) );
    QStringList CommErrorsElemNames;
    CommErrorsElemNames.append("Attitude");
    CommErrorsElemNames.append("AttitudeRaw");
    CommErrorsElemNames.append("PositionActual");
    CommErrorsElemNames.append("HomeLocation");
    CommErrorsElemNames.append("Altitude");
    CommErrorsElemNames.append("Calibration");
    fields.append( new UAVObjectField(QString("CommErrors"), QString("count"), UAVObjectField::UINT8, CommErrorsElemNames, QStringList()) );
    QStringList HomeSetElemNames;
    HomeSetElemNames.append("0");
    QStringList HomeSetEnumOptions;
    HomeSetEnumOptions.append("FALSE");
    HomeSetEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("HomeSet"), QString(""), UAVObjectField::ENUM, HomeSetElemNames, HomeSetEnumOptions) );
    QStringList CalibrationSetElemNames;
    CalibrationSetElemNames.append("0");
    QStringList CalibrationSetEnumOptions;
    CalibrationSetEnumOptions.append("FALSE");
    CalibrationSetEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("CalibrationSet"), QString(""), UAVObjectField::ENUM, CalibrationSetElemNames, CalibrationSetEnumOptions) );

    // Initialize object
    initializeFields(fields, (quint8*)&data, NUMBYTES);
    // Set the default field values
    setDefaultFieldValues();
}

/**
 * Get the default metadata for this object
 */
UAVObject::Metadata AhrsStatus::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flightAccess = ACCESS_READWRITE;
    metadata.gcsAccess = ACCESS_READWRITE;
    metadata.gcsTelemetryAcked = 0;
    metadata.gcsTelemetryUpdateMode = UAVObject::UPDATEMODE_MANUAL;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.flightTelemetryAcked = 0;
    metadata.flightTelemetryUpdateMode = UAVObject::UPDATEMODE_PERIODIC;
    metadata.flightTelemetryUpdatePeriod = 1000;
    metadata.loggingUpdateMode = UAVObject::UPDATEMODE_PERIODIC;
    metadata.loggingUpdatePeriod = 1000;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void AhrsStatus::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
AhrsStatus::DataFields AhrsStatus::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void AhrsStatus::setData(const DataFields& data)
{
    QMutexLocker locker(mutex);
    // Get metadata
    Metadata mdata = getMetadata();
    // Update object if the access mode permits
    if ( mdata.gcsAccess == ACCESS_READWRITE )
    {
        this->data = data;
        emit objectUpdatedAuto(this); // trigger object updated event
        emit objectUpdated(this);
    }
}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject* AhrsStatus::clone(quint32 instID)
{
    AhrsStatus* obj = new AhrsStatus();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
AhrsStatus* AhrsStatus::GetInstance(UAVObjectManager* objMngr, quint32 instID)
{
    return dynamic_cast<AhrsStatus*>(objMngr->getObject(AhrsStatus::OBJID, instID));
}
