#include <stdio.h>
#include <string.h>
#include <exception>
#include <fstream>
#include <vector>
#include "TFile.h"
#include "TDirectory.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMacro.h"
#include <TTree.h>
#include <iostream>
#include <sstream>
#include "TH2.h"
#include "TF1.h"
#include "TH3.h"
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;


string GetLocation(string str)
{
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

struct vectorsTree
{
  vector<double> *FEBSN;
  vector<double> *SpillNum;
  vector<double> *GTrigTag;
  vector<double> *GTrigTime;
  vector<double> *hitsChannel;
  vector<double> *hitAmpl;
  vector<double> hitAmplRec;
  vector<double> *hitLGAmpl;
  vector<double> hitLGAmplRec;
  vector<double> hitHG_pe;
  vector<double> hitLG_pe;
  vector<double> hitToT_pe;
  vector<double> hitCharge_pe;
  vector<double> *hitLeadTime;
  vector<double> *hitTrailTime;
  vector<double> *hitTimeDif;
  //vector<double> *hitTimeAvr;
  vector<double> *SpillTime;
  vector<double> *SpillTimeGTrig;
  vector<double> *hitTimefromSpill;
  vector<double> *SpillTrailTime;
  vector<double> *AsicTemperature;
  vector<double> *FPGATemperature;
  vector<double> *GlobalHV;
  vector<double> *BoardTemperature;
  vector<double> *BoardHumidity;
};


int main ()
{   
    int NumberOfFEB=30;
    
    vector<string> vFileNames;
    string sFileName;
    ifstream fList("febs_files_list.list");
    while (!fList.eof()) {
        fList >> sFileName;
        vFileNames.push_back(sFileName);
    }
    string rootFileInput=GetLocation(vFileNames[0].c_str());
    string rootFileOutput=GetLocation (vFileNames[0].c_str());
    rootFileInput+="_all.root";
    rootFileOutput+="_all_reconstructed.root";
    cout << rootFileInput<<endl;
    cout << rootFileOutput<<endl;
    TFile *FileInput = new TFile(rootFileInput.c_str());
    
    TFile wfile(rootFileOutput.c_str(), "recreate");
    TTree* FEBtreer[NumberOfFEB];
    
    vectorsTree FEB[NumberOfFEB];
    
    for (Int_t i=0;i<NumberOfFEB;i++){
        FEB[i].FEBSN=0;
        FEB[i].SpillNum=0;
        FEB[i].hitsChannel=0;
        FEB[i].hitAmpl=0;
        FEB[i].hitLeadTime=0;
        FEB[i].GTrigTag=0;
        FEB[i].GTrigTime=0;
        FEB[i].hitLGAmpl=0;
        FEB[i].hitTrailTime=0;
        FEB[i].hitTimeDif=0;
        //FEB[i].hitTimeAvr=0;
        FEB[i].SpillTime=0;
        FEB[i].SpillTimeGTrig=0;
        FEB[i].hitTimefromSpill=0;
        FEB[i].SpillTrailTime=0;
        FEB[i].AsicTemperature=0;
        FEB[i].FPGATemperature=0;
        FEB[i].GlobalHV=0;
        FEB[i].BoardTemperature=0;
        FEB[i].BoardHumidity=0;
    }
    
    TTree *FEBtree[NumberOfFEB];
    vector<int> FEBnumbers;
    Long64_t nentries[NumberOfFEB];
    FEBnumbers.clear();
    
   ostringstream sFEBnum;
    ostringstream sMCRnum;
    ostringstream sSlotnum;
    string sFEB;

    int Slot;
    int MCR;
    for (Int_t ih=0; ih<NumberOfFEB; ih++) {
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        FEBtree[ih] = (TTree*)FileInput->Get(sFEB.c_str());
        
        if ((TTree*)FileInput->Get(sFEB.c_str())){
            FEBnumbers.push_back(ih);
            std::cout<<sFEB<<" ";
            
            FEBtree[ih]->SetBranchAddress((sFEB+"_SN").c_str(),&FEB[ih].FEBSN);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTag").c_str(),&FEB[ih].SpillNum);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTag").c_str(),&FEB[ih].GTrigTag);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTime").c_str(),&FEB[ih].GTrigTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitsChannel").c_str(),&FEB[ih].hitsChannel);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitAmpl").c_str(),&FEB[ih].hitAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLGAmpl").c_str(),&FEB[ih].hitLGAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLeadTime").c_str(),&FEB[ih].hitLeadTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTrailTime").c_str(),&FEB[ih].hitTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimeDif").c_str(),&FEB[ih].hitTimeDif);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTime").c_str(),&FEB[ih].SpillTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTimeGTrig").c_str(),&FEB[ih].SpillTimeGTrig);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimefromSpill").c_str(),&FEB[ih].hitTimefromSpill);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTrailTime").c_str(),&FEB[ih].SpillTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_AsicTemperature").c_str(),&FEB[ih].AsicTemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_FPGATemperature").c_str(),&FEB[ih].FPGATemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GlobalHV").c_str(),&FEB[ih].GlobalHV);
            FEBtree[ih]->SetBranchAddress((sFEB+"_BoardTemperature").c_str(),&FEB[ih].BoardTemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_BoardHumidity").c_str(),&FEB[ih].BoardHumidity);

            nentries[ih] = FEBtree[ih]->GetEntries();
            cout<< "Number of spills "<< nentries[ih] <<endl;
        
  Double_t fitParToT[96][5];
  Double_t fitParHG_ToT[96][5];
  Double_t fitParHG[96][2];
  Double_t ChannelGain[28][3][96];

        cout <<"FEB " <<ih<<" in process."<<endl;
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        sMCRnum.str("");
        sSlotnum.str("");
        
        Slot = ih% 8;
        MCR = ih / 8;

        sMCRnum << MCR;
        sSlotnum << Slot;
        
        string fintxtLG = "LG_ToT_calib/";
        fintxtLG+=sFEB.c_str();
        fintxtLG+="_LG_ToT_calib.txt";
        
        string fintxtHG_ToT = "HG_ToT_calib/";
        fintxtHG_ToT+=sFEB.c_str();
        fintxtHG_ToT+="_HG_ToT_calib.txt";
        
        string fintxtHG = "HG_LG_calib/";
        fintxtHG+=sFEB.c_str();
        fintxtHG+="_HG_LG_calib.txt";
        
        string fintxtPE_HG = "PE_HG_calib/MCR";
        fintxtPE_HG+=sMCRnum.str();
        fintxtPE_HG+="_Slot_";
        fintxtPE_HG+=sSlotnum.str();
        fintxtPE_HG+="_gain.txt";
        
        FEBtreer[ih] = new TTree(sFEB.c_str(),sFEB.c_str()); 
    
            FEBtreer[ih]->Branch((sFEB+"_SN").c_str(),"vector<double>",&FEB[ih].FEBSN);
            FEBtreer[ih]->Branch((sFEB+"_SpillTag").c_str(),"vector<double>",&FEB[ih].SpillNum);
            FEBtreer[ih]->Branch((sFEB+"_SpillTime").c_str(),"vector<double>",&FEB[ih].SpillTime);
            FEBtreer[ih]->Branch((sFEB+"_SpillTimeGTrig").c_str(),"vector<double>",&FEB[ih].SpillTimeGTrig);
            FEBtreer[ih]->Branch((sFEB+"_GTrigTag").c_str(),"vector<double>",&FEB[ih].GTrigTag);
            FEBtreer[ih]->Branch((sFEB+"_GTrigTime").c_str(),"vector<double>",&FEB[ih].GTrigTime);
            FEBtreer[ih]->Branch((sFEB+"_hitsChannel").c_str(),"vector<double>",&FEB[ih].hitsChannel);
            FEBtreer[ih]->Branch((sFEB+"_hitAmpl").c_str(),"vector<double>",&FEB[ih].hitAmpl);
            FEBtreer[ih]->Branch((sFEB+"_hitLGAmpl").c_str(),"vector<double>",&FEB[ih].hitLGAmpl);
            FEBtreer[ih]->Branch((sFEB+"_hitLeadTime").c_str(),"vector<double>",&FEB[ih].hitLeadTime);
            FEBtreer[ih]->Branch((sFEB+"_hitTrailTime").c_str(),"vector<double>",&FEB[ih].hitTrailTime);
            FEBtreer[ih]->Branch((sFEB+"_hitTimeDif").c_str(),"vector<double>",&FEB[ih].hitTimeDif);
        
            FEBtreer[ih]->Branch((sFEB+"_hitAmplRecon").c_str(),"vector<double>",&FEB[ih].hitAmplRec);
            FEBtreer[ih]->Branch((sFEB+"_hitLGAmplRecon").c_str(),"vector<double>",&FEB[ih].hitLGAmplRec);
            FEBtreer[ih]->Branch((sFEB+"_hitHG_pe").c_str(),"vector<double>",&FEB[ih].hitHG_pe);
            FEBtreer[ih]->Branch((sFEB+"_hitLG_pe").c_str(),"vector<double>",&FEB[ih].hitLG_pe);
            FEBtreer[ih]->Branch((sFEB+"_hitToT_pe").c_str(),"vector<double>",&FEB[ih].hitToT_pe);
            FEBtreer[ih]->Branch((sFEB+"_hitCharge_pe").c_str(),"vector<double>",&FEB[ih].hitCharge_pe);
        
            FEBtreer[ih]->Branch((sFEB+"_hitTimefromSpill").c_str(),"vector<double>",&FEB[ih].hitTimefromSpill);
            FEBtreer[ih]->Branch((sFEB+"_SpillTrailTime").c_str(),"vector<double>",&FEB[ih].SpillTrailTime);
            FEBtreer[ih]->Branch((sFEB+"_AsicTemperature").c_str(),"vector<double>",&FEB[ih].AsicTemperature);
            FEBtreer[ih]->Branch((sFEB+"_FPGATemperature").c_str(),"vector<double>",&FEB[ih].FPGATemperature);
            FEBtreer[ih]->Branch((sFEB+"_GlobalHV").c_str(),"vector<double>",&FEB[ih].GlobalHV);
            FEBtreer[ih]->Branch((sFEB+"_BoardTemperature").c_str(),"vector<double>",&FEB[ih].BoardTemperature);
            FEBtreer[ih]->Branch((sFEB+"_BoardHumidity").c_str(),"vector<double>",&FEB[ih].BoardHumidity);
        
        
        
        
        ifstream finDatLG(fintxtLG.c_str());
        cout << "Taking fit parameters at "<< fintxtLG<<endl;
        int temp=0;
        while (temp<95 && !finDatLG.eof()) {
            finDatLG >> temp >> fitParToT[temp][0] >> fitParToT[temp][1] >> fitParToT[temp][2] >> fitParToT[temp][3] >> fitParToT[temp][4];
            //cout <<temp<<" "<< fitParToT[temp][0] <<" "<< fitParToT[temp][1] <<" "<< fitParToT[temp][2] <<" "<< fitParToT[temp][3]<<" "<< fitParToT[temp][4] <<endl;
        }   
        finDatLG.close();
        
        ifstream finDatHG_ToT(fintxtHG_ToT.c_str());
        cout << "Taking fit parameters at "<< fintxtHG_ToT<<endl;
        temp=0;
        while (temp<95 && !finDatHG_ToT.eof()) {
            finDatHG_ToT >> temp >> fitParHG_ToT[temp][0] >> fitParHG_ToT[temp][1] >> fitParHG_ToT[temp][2] >> fitParHG_ToT[temp][3] >> fitParHG_ToT[temp][4];
            //cout <<temp<<" "<< fitParHG_ToT[temp][0] <<" "<< fitParHG_ToT[temp][1] <<" "<< fitParHG_ToT[temp][2] <<" "<< fitParHG_ToT[temp][3]<<" "<< fitParHG_ToT[temp][4] <<endl;
        }   
        finDatHG_ToT.close();
        
        ifstream finDatHG(fintxtHG.c_str());
        cout << "Taking fit parameters at "<< fintxtHG<<endl;
        temp=0;
        while (temp<95 && !finDatHG.eof()) {
            finDatHG >> temp >> fitParHG[temp][0] >> fitParHG[temp][1] ;
            //cout <<temp<<" "<< fitParHG[temp][0] <<" "<< fitParHG[temp][1] <<endl;
        }   
        finDatHG.close();
        
        ifstream gain(fintxtPE_HG.c_str());
        temp=0;
        if (ih != 12){
            cout << "Taking fit parameters at "<< fintxtPE_HG <<endl;
            while (!gain.eof()) {
            gain >> temp >> ChannelGain[ih][0][temp] >> ChannelGain[ih][1][temp] >> ChannelGain[ih][2][temp];
            }
        gain.close();
        }
        
        for (int ik = 0; ik < nentries[ih]; ik++){
            
        FEBtree[ih]->GetEntry(ik);
        //std::cout << "Number of events  in Spill "<< ik <<" = " <<FEB[ih].FEBSN->size()<<std::endl;
        for ( Int_t iev=0; iev < FEB[ih].FEBSN->size(); iev++){
            if (ih != 12){
            double reconLG =  fitParToT[(int)FEB[ih].hitsChannel->at(iev)][0] * (FEB[ih].hitTimeDif->at(iev)) 
            + fitParToT[(int)FEB[ih].hitsChannel->at(iev)][1] * pow(FEB[ih].hitTimeDif->at(iev),2)
            + fitParToT[(int)FEB[ih].hitsChannel->at(iev)][2] * pow(FEB[ih].hitTimeDif->at(iev),3)
            + fitParToT[(int)FEB[ih].hitsChannel->at(iev)][3] * pow(FEB[ih].hitTimeDif->at(iev),4)
            + fitParToT[(int)FEB[ih].hitsChannel->at(iev)][4] * pow(FEB[ih].hitTimeDif->at(iev),5);
            
            double reconHG =  fitParHG_ToT[(int)FEB[ih].hitsChannel->at(iev)][0] * (FEB[ih].hitTimeDif->at(iev)) 
            + fitParHG_ToT[(int)FEB[ih].hitsChannel->at(iev)][1] * pow(FEB[ih].hitTimeDif->at(iev),2)
            + fitParHG_ToT[(int)FEB[ih].hitsChannel->at(iev)][2] * pow(FEB[ih].hitTimeDif->at(iev),3)
            + fitParHG_ToT[(int)FEB[ih].hitsChannel->at(iev)][3] * pow(FEB[ih].hitTimeDif->at(iev),4)
            + fitParHG_ToT[(int)FEB[ih].hitsChannel->at(iev)][4] * pow(FEB[ih].hitTimeDif->at(iev),5);
            
            if (FEB[ih].hitTimeDif->at(iev)<100 && reconLG >= 0 && FEB[ih].hitTimeDif->at(iev) > 0) {
                FEB[ih].hitLGAmplRec.push_back(reconLG);
            } else
                FEB[ih].hitLGAmplRec.push_back(FEB[ih].hitLGAmpl->at(iev));
            
            if (FEB[ih].hitTimeDif->at(iev)<20 && reconHG >= 0) {
                FEB[ih].hitAmplRec.push_back(reconHG);
            } else if (FEB[ih].hitTimeDif->at(iev)<100 && FEB[ih].hitTimeDif->at(iev)>=20 && ((reconLG - fitParHG[(int)FEB[ih].hitsChannel->at(iev)][0])/ fitParHG[(int)FEB[ih].hitsChannel->at(iev)][0]) >= 0 && FEB[ih].hitTimeDif->at(iev) > 0) {
                FEB[ih].hitAmplRec.push_back((reconLG - fitParHG[(int)FEB[ih].hitsChannel->at(iev)][0])/ fitParHG[(int)FEB[ih].hitsChannel->at(iev)][0]);
            } else 
                FEB[ih].hitAmplRec.push_back(FEB[ih].hitAmpl->at(iev));
            
            double reconHG_pe, reconLG_pe, reconToT_pe;

            //making hitHG_pe
            if (FEB[ih].hitAmpl->at(iev)>0){
              reconHG_pe = (FEB[ih].hitAmpl->at(iev) - ChannelGain[ih][2][(int)FEB[ih].hitsChannel->at(iev)]) / ChannelGain[ih][0][(int)FEB[ih].hitsChannel->at(iev)];
              FEB[ih].hitHG_pe.push_back(reconHG_pe);
            } else{
              reconHG_pe = 0;
              FEB[ih].hitHG_pe.push_back(0);
            }

            //making hitLG_pe
            if (FEB[ih].hitAmpl->at(iev)>0){
              reconLG_pe = (((FEB[ih].hitLGAmpl->at(iev) - fitParHG[(int)FEB[ih].hitsChannel->at(iev)][0])/fitParHG[(int)FEB[ih].hitsChannel->at(iev)][1]) - ChannelGain[ih][2][(int)FEB[ih].hitsChannel->at(iev)]) / ChannelGain[ih][0][(int)FEB[ih].hitsChannel->at(iev)];
              FEB[ih].hitLG_pe.push_back(reconLG_pe);
            } else {
              reconLG_pe = 0;
              FEB[ih].hitLG_pe.push_back(0);
            }


            //making hitToT_pe
            if (FEB[ih].hitAmplRec.back()>0){
              reconToT_pe = (FEB[ih].hitAmplRec.back() - ChannelGain[ih][2][(int)FEB[ih].hitsChannel->at(iev)]) / ChannelGain[ih][0][(int)FEB[ih].hitsChannel->at(iev)];
              FEB[ih].hitToT_pe.push_back(reconToT_pe);
            } else {
              reconToT_pe = -1;
              FEB[ih].hitToT_pe.push_back(reconToT_pe);
            }


            //making hitCharge_pe
            if (reconHG_pe>0 && FEB[ih].hitAmpl->at(iev)<3000){
              FEB[ih].hitCharge_pe.push_back(reconHG_pe);
            } else if (reconLG_pe>0 && FEB[ih].hitLGAmpl->at(iev)<3000){
              FEB[ih].hitCharge_pe.push_back(reconLG_pe);
            } else {
              FEB[ih].hitCharge_pe.push_back(reconToT_pe);
            }
          }
          else{
            FEB[ih].hitAmplRec.push_back(0);
            FEB[ih].hitLGAmplRec.push_back(0);
            FEB[ih].hitHG_pe.push_back(0);
            FEB[ih].hitLG_pe.push_back(0);
            FEB[ih].hitCharge_pe.push_back(0);
            FEB[ih].hitToT_pe.push_back(0);
          }
        }
        FEBtreer[ih]->Fill();
        
        FEB[ih].FEBSN->clear();
        FEB[ih].SpillNum->clear();
        FEB[ih].hitsChannel->clear();
        FEB[ih].hitAmpl->clear();
        FEB[ih].hitLeadTime->clear();
        FEB[ih].GTrigTag->clear();
        FEB[ih].GTrigTime->clear();
        FEB[ih].hitLGAmpl->clear();
        FEB[ih].hitTrailTime->clear();
        FEB[ih].hitTimeDif->clear();
        //FEB[ih].hitTimeAvr->clear();
        FEB[ih].SpillTime->clear();
        FEB[ih].SpillTimeGTrig->clear();
        FEB[ih].hitTimefromSpill->clear();
        FEB[ih].SpillTrailTime->clear();
        FEB[ih].AsicTemperature->clear();
        FEB[ih].FPGATemperature->clear();
        FEB[ih].GlobalHV->clear();
        FEB[ih].BoardTemperature->clear();
        FEB[ih].BoardHumidity->clear();
        
        FEB[ih].hitAmplRec.clear();
        FEB[ih].hitLGAmplRec.clear();
        FEB[ih].hitHG_pe.clear();
        FEB[ih].hitLG_pe.clear();
        FEB[ih].hitToT_pe.clear();
        FEB[ih].hitCharge_pe.clear();
        }
    FEBtreer[ih]-> Write("",TObject::kOverwrite);
    FEBtreer[ih]->Delete();
      }
    
    }

  FileInput->Close();
  wfile.Close();
  return 0;
}
